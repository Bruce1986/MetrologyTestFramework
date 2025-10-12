# Contributing to the Metrology Test Framework

Thank you for your interest in helping build a reliable, open-source metrology test framework. This project values clear communication, reproducibility, and a collaborative review process. Please follow the guidelines below when proposing changes.

## 1. Development Environment
- **Primary reference platform:** Ubuntu 22.04 LTS (x86_64) with GCC 11, CMake ≥ 3.22, and Ninja.
- **Secondary platform notes:** Document any Windows 10 + MSVC 2022 considerations you encounter so that we can expand official support incrementally.
- Use the scripts and instructions in [`DESIGN_DOCUMENT.md`](DESIGN_DOCUMENT.md) as the authoritative source for project structure and build orchestration during the initial sprint.

## 2. Workflow & Branching
- Create a feature branch for every task. Use a descriptive name such as `feature/<short-description>`.
- Follow the pull request workflow outlined in [`project-handbook.md`](project-handbook.md). Include references to issue or task IDs when available.
- Keep commits focused. Update the shared worklog templates in the handbook before each commit, as required by the project guidelines.

## 3. Coding Standards & Testing
- Write clear, intention-revealing identifiers. Functions should be verb-oriented (e.g., `calculateOffsets`).
- Add or update Google Test unit tests for every new function or behavior change. If adding a test is impractical, explain why in the pull request discussion.
- Run the CMake build (`cmake -B build && cmake --build build`) and execute the test suite (`ctest --test-dir build --output-on-failure`) before submitting a pull request.

## 4. Dependency Management
- Declare all third-party dependencies through centralized CMake modules (e.g., `cmake/Dependencies.cmake`). Use `find_package` first; fall back to `FetchContent` only when necessary.
- When proprietary or unavailable vendor libraries are needed, provide mock or stub implementations so the open-source build remains reproducible.
- Document new dependencies in both the CMake files and the pull request description, including license considerations.

## 5. Documentation & Review
- Update relevant documentation (README, design docs, diagrams) alongside code changes.
- Respond thoughtfully to all review feedback, including automated reviewers such as Gemini Code Assist. If you choose not to implement a suggestion, document the rationale in the pull request.
- Provide self-test evidence in the pull request description so reviewers can validate your changes quickly.

We appreciate your contributions and commitment to open metrology tooling!
