// Week 2 warm-up: predict each line's output BEFORE you run this program.
//
//   cmake -S . -B build
//   cmake --build build --config Release --target path_warmup
//   build/path_warmup            (Windows: build\Release\path_warmup.exe)

#include <filesystem>
#include <iostream>

using std::filesystem::path;

int main() {
    std::cout << std::boolalpha;

    std::cout << "1. " << (path("repo") / ".minigit").generic_string() << '\n';
    std::cout << "2. " << (path("repo") / "/HEAD").generic_string() << '\n';

    path joined = "repo";
    joined += "HEAD";
    std::cout << "3. " << joined.generic_string() << '\n';

    std::cout << "4. " << path("docs/n.txt").parent_path().generic_string() << '\n';
    std::cout << "5. " << path("d/../../a").lexically_normal().generic_string() << '\n';
    std::cout << "6. " << (path("a/./b") == path("a/b")) << '\n';

    // Bonus: printing a path directly adds quotes.
    std::cout << "7. " << path("a/b") << '\n';
    return 0;
}
