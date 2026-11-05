# Working in VS Code (with GitHub Desktop as an option)

Both tools run the same Git commands. You can manage branches and pushes in either one, but you edit code, build, test and resolve conflicts in VS Code.

## One-time setup

1. Install [VS Code](https://code.visualstudio.com/), Git, CMake and a C++17 compiler (on Windows: Visual Studio 2022 with **Desktop development with C++**).
2. Clone the repo: in VS Code, **Command Palette** (`Ctrl+Shift+P`) › **Git: Clone**, or in GitHub Desktop **File › Clone repository**.
3. Open the **repository folder** in VS Code (**File › Open Folder**), not a single file, so Source Control and the terminal start in the repo root.
4. When VS Code suggests the recommended extensions for this repo, install them: **C/C++**, **CMake Tools** and **GitHub Pull Requests**.

## Each issue, step by step

| Step | VS Code | GitHub Desktop |
| --- | --- | --- |
| Get the latest `main` | Click the branch name in the bottom-left status bar, choose `main`, then click **Sync** (the circular arrows) | **Current Branch** › `main`, then **Fetch origin** and **Pull origin** |
| Create your branch | Click the branch name › **Create new branch…**, type `issue-<number>-short-name` | **Current Branch** › **New Branch**, based on `main` |
| Edit code | Explorer view | **Open in Visual Studio Code** |
| Build and test | **Terminal › New Terminal**, then run the three commands below | Use the VS Code terminal |
| Commit | **Source Control** (`Ctrl+Shift+G`): click **+** on each file to stage, type a message, **Commit** | Tick the files, write a summary, **Commit to issue-…** |
| Push | **Publish Branch** the first time, then **Sync Changes** | **Publish branch**, then **Push origin** |
| Open the PR | GitHub Pull Requests extension: **Create Pull Request**; or open the repo in the browser and click **Compare & pull request** | **Preview Pull Request** › **Create pull request** |

Build and test commands, from the repo root:

```
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

## Updating your branch and fixing a merge conflict

When another team's PR is merged first, your PR may say **This branch has conflicts**. Fix it on your computer, not with GitHub's web **Resolve conflicts** button: the web editor cannot build or run the tests.

**VS Code**

1. Commit or stash your own changes first.
2. In the terminal, on your branch:

   ```
   git fetch origin
   git merge origin/main
   ```

3. Conflicted files appear under **Merge Changes** in Source Control, marked **C**.
4. Open each one. Above each conflict VS Code shows **Accept Current Change | Accept Incoming Change | Accept Both Changes | Compare Changes**. When two teams each added a function, choose **Accept Both Changes**, then fix the order and blank lines by hand. You can also click **Resolve in Merge Editor** for a side-by-side view.
5. Rebuild and rerun CTest. Every test must pass.
6. Stage the files (**+**), **Commit** (the message is pre-filled as a merge), then **Sync Changes**.

**GitHub Desktop**

1. On your branch, choose **Branch › Update from main**.
2. Desktop lists the conflicted files. Click **Open in Visual Studio Code** and follow steps 4 and 5 above.
3. Back in Desktop, click **Continue merge**, then **Push origin**.

Never delete another team's code to make a conflict go away.
