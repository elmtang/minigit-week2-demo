#include "PathLab.hpp"
#include <chrono>
#include <iostream>

bool check(bool condition, const char* message) {
    if (!condition) {
        std::cerr << "FAILED: " << message << '\n';
        return false;
    }
    return true;
}

int main() {
    const std::filesystem::path root = "course/repo";
    const std::filesystem::path nestedRoot = "course/team/repo";

    if (!check(minigit::metadataDirectory(root) == root / ".minigit",
               "metadata directory for ordinary root")) return 1;
    if (!check(minigit::metadataDirectory(nestedRoot) == nestedRoot / ".minigit",
               "metadata directory for nested root")) return 1;
    if (!check(minigit::headFile(root) == root / ".minigit" / "HEAD",
               "HEAD path for ordinary root")) return 1;
    if (!check(minigit::headFile(nestedRoot) == nestedRoot / ".minigit" / "HEAD",
               "HEAD path for nested root")) return 1;

    const auto stamp = std::chrono::steady_clock::now().time_since_epoch().count();
    const auto tempRoot = std::filesystem::temp_directory_path() /
                          ("pathlab-tests-" + std::to_string(stamp));
    const auto file = tempRoot / "new" / "nested" / "note.txt";
    std::string error;
    bool passed = true;

    if (!check(minigit::writeTextFile(file, "hello MiniGit", error),
               "write text in a new nested folder")) {
        std::cerr << error << '\n';
        passed = false;
    }

    std::string text;
    if (!check(minigit::readTextFile(file, text, error),
               "read the file that was written")) {
        std::cerr << error << '\n';
        passed = false;
    }
    if (!check(text == "hello MiniGit", "read back the exact text")) {
        passed = false;
    }

    const auto missingFile = tempRoot / "missing.txt";
    if (!check(!minigit::readTextFile(missingFile, text, error),
               "report a missing file")) {
        passed = false;
    }
    if (!check(!error.empty(), "provide an error message for a missing file")) {
        passed = false;
    }

    std::filesystem::remove_all(tempRoot);
    if (!passed) return 1;

    std::cout << "All path and text file tests passed\n";
    return 0;
}
