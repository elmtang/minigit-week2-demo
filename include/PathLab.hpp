#pragma once
#include <filesystem>
#include <string>

namespace minigit {

// Return the path to the metadata folder inside a repository.
// This builds a path only; it does not create the folder.
std::filesystem::path metadataDirectory(const std::filesystem::path& root);

// Return the path to the HEAD file inside the metadata folder.
std::filesystem::path headFile(const std::filesystem::path& root);

// Create missing parent folders and write text to a file.
// Return true on success; otherwise place a short message in errorMessage.
bool writeTextFile(const std::filesystem::path& file,
                   const std::string& text,
                   std::string& errorMessage);

// Read all text from a file.
// Return true on success; otherwise place a short message in errorMessage.
bool readTextFile(const std::filesystem::path& file,
                  std::string& text,
                  std::string& errorMessage);

} // namespace minigit
