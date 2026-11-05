## Related Issue
Closes #<number>   <!-- replace <number> with the real issue number -->

## What changed
- 

## How I tested
- [ ] `cmake -S . -B build`
- [ ] `cmake --build build --config Release`
- [ ] `ctest --test-dir build -C Release --output-on-failure` (paste the result below)
- [ ] Windows CI passed
- [ ] Ubuntu CI passed

```
paste CTest output here
```

## Reviewer focus
Please check:
- [ ] The change matches the Issue acceptance criteria and nothing out of scope.
- [ ] Paths are built with `std::filesystem::path` and `/`, not strings and `+`.
- [ ] Tests compare `path` values and cover a sub-folder or nested root.
- [ ] Any new test program is registered in `CMakeLists.txt`.
- [ ] Both CI checks are green.

A classmate's review is required; a bot approval alone does not count. Do not merge until the instructor approves.
