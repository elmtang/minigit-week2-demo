# FileSystem starter

These files let your team build the `FileSystem` class one function at a time. The header, the tests and the CMake setup are done for you. Each issue only fills in one function body in `src/FileSystem.cpp`.

## Step 0: add the starter to your HW8 repository (one member, one small PR)

1. Create a branch from an up-to-date `main`, for example `add-filesystem-starter`.
2. Copy these files into your repository at the same paths:

   | From this folder | To your repository |
   | --- | --- |
   | `include/FileSystem.hpp` | `include/FileSystem.hpp` |
   | `src/FileSystem.cpp` | `src/FileSystem.cpp` |
   | `tests/FileSystemTests.cpp` | `tests/FileSystemTests.cpp` |
   | `issue-drafts/11` to `14` | `issue-drafts/` |

3. Edit `CMakeLists.txt` in two places:

   ```cmake
   # 1. add src/FileSystem.cpp to the library
   add_library(minigit_paths src/PathLab.cpp src/FileSystem.cpp)
   ```

   ```cmake
   # 2. inside if(BUILD_TESTING), after the existing tests
       add_executable(file_system_tests tests/FileSystemTests.cpp)
       target_link_libraries(file_system_tests PRIVATE minigit_paths)
       add_test(NAME file_system_tests COMMAND file_system_tests)
   ```

   If your repository already has `src/RepositoryPaths.cpp` in `add_library`, keep it and add `src/FileSystem.cpp` after it. If your library has a different name, use that name.

4. Build and test:

   ```
   cmake -S . -B build
   cmake --build build --config Release
   ctest --test-dir build -C Release --output-on-failure -V
   ```

   CTest passes. In the output, `file_system_tests` prints `SKIPPED` four times and ends with `0 failed, 4 skipped`.

5. Commit, push, open a PR to `main`, get a teammate's review, merge.
6. Publish drafts `11` to `14` as GitHub issues and assign them.

## Then each issue

1. Branch from the updated `main`: `issue-<number>-short-name`.
2. In `src/FileSystem.cpp`, find your function. Delete its `throw std::logic_error(...)` line and write the code, following the hints in the comments.
3. Build and run CTest with `-V`. Your section changes from `SKIPPED` to `PASS`. Any `FAIL` must be fixed before you open the PR.
4. Commit, push, PR with `Closes #<number>`, teammate review, merge.

You do not need to edit the header, the tests or `CMakeLists.txt` in FS-1 to FS-4.
