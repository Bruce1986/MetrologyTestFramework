# Contributing to the Metrology Test Framework

Thank you for your interest in helping build a reliable, open-source metrology test framework. This project values clear communication, reproducibility, and a collaborative review process. Please follow the guidelines below when proposing changes.

## 1. Development Environment
- **Primary reference platform:** Ubuntu 22.04 LTS (x86_64) with GCC 11, CMake ≥ 3.22, and Ninja.
- **Secondary platform notes:** Document any Windows 10 + MSVC 2022 considerations you encounter so that we can expand official support incrementally.
- **macOS support status:** Currently untested. Contributors working on macOS should record any required toolchains, build flags, or issues so the team can assess and document official support.
- Refer to [`DESIGN_DOCUMENT.md`](DESIGN_DOCUMENT.md) for details on the project's architecture, structure, and implementation plan for the initial sprint.

## 2. Workflow & Branching
- Create a feature branch for every task. Use a descriptive name such as `feature/<short-description>`.
- Capture the intent of each commit and keep them focused. Update the shared worklog as detailed in [`WORKLOG.md`](WORKLOG.md) before each commit so teammates can follow your progress.
- When opening a pull request, format the title as `[Type] Brief summary (#TaskID)` (for example, `[Feature] Add calibration mocks (#042)`). Summarize the change, link related discussions or issues, and attach evidence of self-testing.
- Request at least one reviewer and respond to all feedback, including suggestions from automated reviewers such as Gemini Code Assist, before merging.
- Document active tasks in the issue tracker or shared planning board so the team can monitor ownership and dependencies.

## 3. Coding Standards & Testing
- Write clear, intention-revealing identifiers. Functions should be verb-oriented (e.g., `calculateOffsets`).
- Add or update Google Test unit tests for every new function or behavior change. If adding a test is impractical, explain why in the pull request discussion.
- Use the project’s automation script to validate your change: `./run_tests.sh`. This script configures CMake, builds the project, and executes the test suite in one step.
- If the script is temporarily unavailable, run `cmake -B build && cmake --build build --parallel && ctest --test-dir build --output-on-failure` and note the fallback in your pull request.

## 4. Dependency Management
- Declare all third-party dependencies through centralized CMake modules (e.g., `cmake/Dependencies.cmake`). Use `find_package` first; fall back to `FetchContent` only when necessary.
- When proprietary or unavailable vendor libraries are needed, provide mock or stub implementations so the open-source build remains reproducible.
- Document new dependencies in both the CMake files and the pull request description, including license considerations.

## 5. Documentation & Review
- Update relevant documentation (README, design docs, diagrams) alongside code changes.
- Respond thoughtfully to all review feedback, including automated reviewers such as Gemini Code Assist. If you choose not to implement a suggestion, document the rationale in the pull request.
- Provide self-test evidence in the pull request description so reviewers can validate your changes quickly.

## 6. Review Checklist
- [ ] Names are intention-revealing (functions use verb phrases such as `calculateOffsets`).
- [ ] Error handling and logging paths are covered where applicable.
- [ ] New functionality includes accompanying Google Test unit tests.
- [ ] Documentation (README, design docs, inline comments) has been updated.
- [ ] `./run_tests.sh` completes successfully and its output is attached to the pull request.
- [ ] New dependencies are documented and follow project guidelines.
- [ ] Known follow-ups or limitations are captured in issues or TODO comments.

We appreciate your contributions and commitment to open metrology tooling!
