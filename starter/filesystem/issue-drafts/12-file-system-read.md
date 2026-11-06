# Issue FS-2 Implement FileSystem::read(file)

## Goal
Fill in `FileSystem::read` so it returns a whole file exactly as stored.

## Dependency
FS-1 merged (the tests use `write` to create files).

## What to do
In `src/FileSystem.cpp`, replace the `throw std::logic_error(...)` line in `read` with real code, following the hints. Compare with HW8's `readTextFile`.

## Acceptance criteria
- The file is opened in binary mode and every byte is returned, including `\n` and an empty file.
- The whole file is read at once (`rdbuf()`), not line by line.
- If the file cannot be opened, throw `std::runtime_error` naming the file.
- The `FS-2 read` checks show `PASS`, and nothing shows `FAIL`.
- Windows and Ubuntu CI pass.

## Out of scope
The other functions. Do not edit the header, the tests or `CMakeLists.txt`.

## Reviewer focus
What would go wrong with `std::getline` here? Is `std::runtime_error` (not `logic_error`) thrown for a missing file?
