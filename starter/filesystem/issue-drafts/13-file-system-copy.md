# Issue FS-3 (optional) Implement FileSystem::copy(source, target)

## Goal
Fill in `FileSystem::copy` so it copies one file, creating folders and replacing an existing target.

## Dependency
FS-1 and FS-2 merged (the tests use both).

## What to do
In `src/FileSystem.cpp`, replace the `throw std::logic_error(...)` line in `copy` with real code, following the hints.

## Acceptance criteria
- Missing parent folders of `target` are created.
- `std::filesystem::copy_file` is called with `copy_options::overwrite_existing`.
- A missing source throws (`copy_file` already does this; do not catch it).
- The `FS-3 copy` checks show `PASS`, and nothing shows `FAIL`.
- Windows and Ubuntu CI pass.

## Out of scope
Copying folders. Do not edit the header, the tests or `CMakeLists.txt`.

## Reviewer focus
Which check fails if `overwrite_existing` is left out?
