# CSC350 MiniGit Week 2: RepositoryPaths

Class demo repository for Week 2. `main` starts where HW8 ended: `PathLab` has `metadataDirectory`, `headFile`, `writeTextFile` and `readTextFile`, with passing tests. This week we build the first shared foundation class from the HW7 design, `RepositoryPaths`.

## Tools

We use **VS Code** to edit, build, test, commit and resolve conflicts. **GitHub Desktop** also works for branches and pushing. See [`docs/vscode-and-github-desktop.md`](docs/vscode-and-github-desktop.md) for each step in both tools. Open the repository folder in VS Code and install the recommended extensions when it asks.

## Build and test

From the repository root (the VS Code terminal, Developer PowerShell on Windows, or any terminal with CMake and a C++17 compiler):

```
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

## Warm-up

`warmup/path_warmup.cpp` prints seven `std::filesystem::path` expressions. Predict each result first, then run:

```
cmake --build build --config Release --target path_warmup
build/path_warmup                 # Windows: build\Release\path_warmup.exe
```

## Issues for this week

The drafts are in [`issue-drafts/`](issue-drafts/). Copy a draft into a GitHub issue (**Issues → New issue**) before you start.

| Draft | Issue | Depends on |
| --- | --- | --- |
| `05` | RP-1 Create RepositoryPaths with its two roots (class demo) | HW8 |
| `06` | RP-2 `headFile()` and `indexFile()` | RP-1 |
| `07` | RP-3 `stageFile(path)` | RP-1 |
| `08` | RP-4 `commitDirectory(id)` and `committedFile(id, path)` | RP-1 |
| `09` | RP-5 `safeRelativeFile(argument)` | RP-1 |
| `10` | RP-6 (stretch) reject symbolic links | RP-5 |

RP-2 to RP-5 can be built at the same time by different teams once RP-1 is merged. They all edit the same three files, so expect a merge conflict when you update your branch from `main`: keep both sides, rebuild and rerun the tests.

## Workflow

1. Publish the issue from its draft and assign yourself.
2. Create a branch from an up-to-date `main`: `issue-<number>-short-name`.
3. Implement only what the issue asks, with its tests. Register new test programs in `CMakeLists.txt`.
4. Run the three commands above.
5. Push and open a PR into `main` with `Closes #<number>`.
6. A classmate reviews (a bot approval alone does not count) and leaves at least one comment about path handling.
7. Merge only when Windows and Ubuntu CI pass and the instructor approves.

See `docs/` for the CMake/CI guide, the review checklist and the submission sheet.
