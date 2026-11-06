# Issue FS-1 Implement FileSystem::write(file, text)

## Goal
Fill in `FileSystem::write` so it writes exact text to a file, creating any missing folders first.

## Dependency
The FileSystem starter is merged (see `starter/filesystem/README.md`, Step 0).

## What to do
In `src/FileSystem.cpp`, replace the `throw std::logic_error(...)` line in `write` with real code. The comments there give hints. You wrote similar code in HW8's `writeTextFile`.

## Acceptance criteria
- Missing parent folders are created with `std::filesystem::create_directories`.
- The file is opened in binary mode and its old content is replaced.
- If the file cannot be opened or written, throw `std::runtime_error` naming the file.
- The `FS-1 write` checks in `file_system_tests` show `PASS`, and nothing shows `FAIL`.
- Windows and Ubuntu CI pass.

## Out of scope
The other three functions. Do not edit the header, the tests or `CMakeLists.txt`.

## Reviewer focus
Is the file opened with `std::ios::binary`? Does the error message include the file name?
