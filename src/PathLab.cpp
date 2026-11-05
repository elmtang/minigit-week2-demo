#include "PathLab.hpp"
#include <fstream>
#include <sstream>

namespace minigit {

std::filesystem::path metadataDirectory(const std::filesystem::path& root) {
    return root / ".minigit";
}

std::filesystem::path headFile(const std::filesystem::path& root) {
    return metadataDirectory(root) / "HEAD";
}

bool writeTextFile(const std::filesystem::path& file,
                   const std::string& text,
                   std::string& errorMessage) {
    errorMessage.clear();

    const std::filesystem::path parent = file.parent_path();
    if (!parent.empty()) {
        std::error_code error;
        std::filesystem::create_directories(parent, error);
        if (error) {
            errorMessage = error.message();
            return false;
        }
    }

    std::ofstream output(file);
    if (!output) {
        errorMessage = "Could not open file for writing: " + file.string();
        return false;
    }

    output << text;
    if (!output) {
        errorMessage = "Could not write to file: " + file.string();
        return false;
    }

    return true;
}

bool readTextFile(const std::filesystem::path& file,
                  std::string& text,
                  std::string& errorMessage) {
    errorMessage.clear();

    std::ifstream input(file);
    if (!input) {
        errorMessage = "Could not open file for reading: " + file.string();
        return false;
    }

    std::ostringstream contents;
    contents << input.rdbuf();
    if (input.bad()) {
        errorMessage = "Could not read file: " + file.string();
        return false;
    }

    text = contents.str();
    return true;
}

} // namespace minigit
