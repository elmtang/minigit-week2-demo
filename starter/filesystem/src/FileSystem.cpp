#include "FileSystem.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

// Each function below is a stub. When you work on its issue:
//   1. delete the "throw std::logic_error(...)" line;
//   2. write the real code where the hints say;
//   3. build and run the tests: your issue's checks change from SKIPPED to PASS.
// Useful headers are already included above.

namespace minigit {

// FS-1 (issue draft 11)
void FileSystem::write(const std::filesystem::path& file, const std::string& text) const {
    // Hints:
    //   - if file.has_parent_path(), call std::filesystem::create_directories(file.parent_path())
    //   - std::ofstream out(file, std::ios::binary | std::ios::trunc);
    //   - if (!out) throw std::runtime_error("Cannot open file for writing: " + file.string());
    //   - out << text;   then check out again and throw if writing failed
    //   - You wrote similar code in HW8's writeTextFile.
    (void)file;
    (void)text;
    throw std::logic_error("Not implemented yet: FileSystem::write (FS-1)");
}

// FS-2 (issue draft 12)
std::string FileSystem::read(const std::filesystem::path& file) const {
    // Hints:
    //   - std::ifstream in(file, std::ios::binary);
    //   - if (!in) throw std::runtime_error("Cannot open file for reading: " + file.string());
    //   - std::ostringstream buffer;  buffer << in.rdbuf();  return buffer.str();
    //   - Do not read line by line: that loses the '\n' characters.
    (void)file;
    throw std::logic_error("Not implemented yet: FileSystem::read (FS-2)");
}

// FS-3 (issue draft 13)
void FileSystem::copy(const std::filesystem::path& source, const std::filesystem::path& target) const {
    // Hints:
    //   - create target's parent folders, as in write()
    //   - std::filesystem::copy_file(source, target,
    //         std::filesystem::copy_options::overwrite_existing);
    //   - copy_file already throws if source is missing; do not catch it.
    (void)source;
    (void)target;
    throw std::logic_error("Not implemented yet: FileSystem::copy (FS-3)");
}

// FS-4 (issue draft 14)
bool FileSystem::same(const std::filesystem::path& first, const std::filesystem::path& second) const {
    // Hints:
    //   - if either path is not std::filesystem::is_regular_file(...), return false
    //   - otherwise return read(first) == read(second);
    (void)first;
    (void)second;
    throw std::logic_error("Not implemented yet: FileSystem::same (FS-4)");
}

} // namespace minigit
