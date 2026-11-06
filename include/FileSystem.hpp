#pragma once
#include <filesystem>
#include <string>

namespace minigit {

// Byte-level file operations for MiniGit: write, read, copy and compare
// whole files. FileSystem knows nothing about MiniGit's rules.
// On failure these functions throw std::runtime_error (not bool + message
// like HW8's writeTextFile/readTextFile).
class FileSystem {
public:
    // FS-1: create missing parent folders, then replace the file's content
    // with text, byte for byte (binary mode).
    void write(const std::filesystem::path& file, const std::string& text) const;

    // FS-2: return every byte of the file. Throws if it cannot be opened.
    std::string read(const std::filesystem::path& file) const;

    // FS-3: copy source to target, creating target's folders and
    // replacing target if it already exists.
    void copy(const std::filesystem::path& source, const std::filesystem::path& target) const;

    // FS-4: true only when both paths are regular files with identical bytes.
    // Never throws for a missing file.
    bool same(const std::filesystem::path& first, const std::filesystem::path& second) const;
};

} // namespace minigit
