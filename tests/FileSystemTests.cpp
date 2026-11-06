// Tests for the FileSystem class. You do NOT need to edit this file.
//
// A test whose function still throws std::logic_error("Not implemented yet")
// is reported as SKIPPED, so CTest and CI stay green while the team works.
// When you finish your issue, its checks change from SKIPPED to PASS.
// To see the SKIPPED / PASS lines, run:
//   ctest --test-dir build -C Release --output-on-failure -V

#include "FileSystem.hpp"

#include <chrono>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>

namespace fs = std::filesystem;

namespace {

int failures = 0;
int skipped = 0;

void check(bool condition, const std::string& message) {
    if (condition) {
        std::cout << "  PASS  " << message << '\n';
    } else {
        std::cout << "  FAIL  " << message << '\n';
        ++failures;
    }
}

// Run one issue's tests; report SKIPPED if a function is still a stub.
template <typename Test>
void runTest(const std::string& name, Test test) {
    std::cout << name << '\n';
    try {
        test();
    } catch (const std::logic_error& error) {
        std::cout << "  SKIPPED  " << error.what() << '\n';
        ++skipped;
    } catch (const std::exception& error) {
        std::cout << "  FAIL  unexpected exception: " << error.what() << '\n';
        ++failures;
    }
}

// True when calling action throws std::runtime_error (or a type derived from it).
template <typename Action>
bool throwsRuntimeError(Action action) {
    try {
        action();
    } catch (const std::runtime_error&) {
        return true;
    }
    return false;
}

// A new, empty folder for this test run, removed again at the end of main().
fs::path makeTempFolder() {
    const auto stamp = std::chrono::steady_clock::now().time_since_epoch().count();
    const fs::path folder = fs::temp_directory_path() / ("minigit-fs-tests-" + std::to_string(stamp));
    fs::create_directories(folder);
    return folder;
}

// FS-1
void testWrite(const fs::path& temp) {
    const minigit::FileSystem files;

    const fs::path nested = temp / "a" / "b" / "note.txt";
    files.write(nested, "hello");
    check(fs::exists(nested), "write creates missing folders and the file");
    check(fs::file_size(nested) == 5, "write stores exactly 5 bytes for \"hello\"");

    const fs::path lines = temp / "lines.txt";
    files.write(lines, "line1\nline2");
    check(fs::file_size(lines) == 11, "binary mode: \"line1\\nline2\" is 11 bytes on every platform");

    files.write(lines, "abc");
    check(fs::file_size(lines) == 3, "a second write replaces the old content");
}

// FS-2
void testRead(const fs::path& temp) {
    const minigit::FileSystem files;

    const fs::path file = temp / "read.txt";
    files.write(file, "line1\nline2");
    check(files.read(file) == "line1\nline2", "read returns the exact bytes, newlines included");

    const fs::path empty = temp / "empty.txt";
    files.write(empty, "");
    check(files.read(empty).empty(), "read of an empty file returns \"\"");

    check(throwsRuntimeError([&] { files.read(temp / "missing.txt"); }),
          "read of a missing file throws std::runtime_error");
}

// FS-3
void testCopy(const fs::path& temp) {
    const minigit::FileSystem files;

    const fs::path first = temp / "first.txt";
    const fs::path second = temp / "second.txt";
    const fs::path target = temp / "new" / "folder" / "copy.txt";
    files.write(first, "first");
    files.write(second, "second version");

    files.copy(first, target);
    check(files.read(target) == "first", "copy creates missing folders and copies the content");

    files.copy(second, target);
    check(files.read(target) == "second version", "copy replaces an existing target");

    check(throwsRuntimeError([&] { files.copy(temp / "missing.txt", temp / "x.txt"); }),
          "copy of a missing source throws std::runtime_error");
}

// FS-4
void testSame(const fs::path& temp) {
    const minigit::FileSystem files;

    const fs::path a = temp / "same-a.txt";
    const fs::path b = temp / "same-b.txt";
    const fs::path c = temp / "same-c.txt";
    files.write(a, "abc");
    files.write(b, "abc");
    files.write(c, "abc\n");

    check(files.same(a, b), "same is true for identical files");
    check(!files.same(a, c), "same is false when only a final newline differs");

    bool missingResult = true;
    bool missingThrew = false;
    try {
        missingResult = files.same(a, temp / "missing.txt");
    } catch (const std::runtime_error&) {
        missingThrew = true;
    }
    check(!missingThrew && !missingResult, "same is false (and does not throw) when a file is missing");

    check(!files.same(temp, a), "same is false when one path is a folder");
}

} // namespace

int main() {
    const fs::path temp = makeTempFolder();

    runTest("FS-1 write", [&] { testWrite(temp); });
    runTest("FS-2 read", [&] { testRead(temp); });
    runTest("FS-3 copy", [&] { testCopy(temp); });
    runTest("FS-4 same", [&] { testSame(temp); });

    std::error_code cleanupError;
    fs::remove_all(temp, cleanupError);

    std::cout << '\n' << failures << " failed, " << skipped << " skipped\n";
    return failures == 0 ? 0 : 1;
}
