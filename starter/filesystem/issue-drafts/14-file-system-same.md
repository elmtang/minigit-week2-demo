# Issue FS-4 (optional) Implement FileSystem::same(first, second)

## Goal
Fill in `FileSystem::same` so it reports whether two files contain identical bytes.

## Dependency
FS-1 and FS-2 merged (`same` uses `read`).

## What to do
In `src/FileSystem.cpp`, replace the `throw std::logic_error(...)` line in `same` with real code, following the hints.

## Acceptance criteria
- Returns `false` unless both paths are regular files (`std::filesystem::is_regular_file`).
- Otherwise returns `read(first) == read(second)`.
- Never throws for a missing file.
- The `FS-4 same` checks show `PASS`, and nothing shows `FAIL`.
- Windows and Ubuntu CI pass.

## Out of scope
Showing line differences. Do not edit the header, the tests or `CMakeLists.txt`.

## Reviewer focus
Is `is_regular_file` checked before `read`, so a missing file returns `false` instead of throwing?
