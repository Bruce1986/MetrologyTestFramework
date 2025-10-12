# Design Document: Foundational Test Framework for Open Metrology Control Software

**Version:** 1.0
**Date:** October 9, 2025
**Author:** Bruce1986

### 1. Introduction & Goals

#### 1.1 Purpose
This document outlines the design and a 4-day implementation plan for a foundational software test framework for a high-precision metrology control platform. The primary purpose of this framework is to introduce automated, repeatable testing into the early stages of the development lifecycle. This will improve code quality, increase developer confidence, and accelerate the delivery of reliable software by enabling the early detection of defects in core control logic.

This framework is intended to be an **open-source project**, encouraging community contribution and collaboration from its inception.

#### 1.2 Core Objectives
The framework is designed to be **targeted, lean, solid, and extensible**. Within the 4-day scope, we will achieve the following specific objectives:

1.  **Validate Logic in Isolation (Unit Testing):** Create a mechanism to test individual C++ classes and functions, particularly those with complex logic, independent of hardware or other system components.
2.  **Verify Component Interactions (Software Integration Testing):** Test the interfaces and interaction sequences between key software modules (e.g., the sequence controller and hardware abstraction layers) in a simulated, software-only environment.
3.  **Establish an Automated Workflow:** Implement a simple, command-line-driven process to build all tests and execute them automatically, providing clear pass/fail feedback.
4.  **Provide a Foundation for Future Expansion:** The architecture will be designed with clear extension points, allowing for the future integration of more complex simulations, open Continuous Integration (CI/CD) pipelines, and eventually Hardware-in-the-Loop (HIL) testing.[^2]

#### 1.3 Non-Goals (Out of Scope for 4-Day Plan)
To ensure focus and successful delivery, the following are explicitly out of scope for this initial implementation:

*   Testing on real target hardware.
*   Hardware-in-the-Loop (HIL) simulation.[^2]
*   Performance, stress, or endurance testing.
*   Testing of high-level algorithms (e.g., image pattern recognition, machine learning models).
*   Full CI/CD pipeline integration (e.g., with Jenkins or GitLab).[^3][^4]

---

### 2. Core Architecture & Technology Choices

The framework will be built on a layered testing approach, focusing on the first two layers of the software testing pyramid: Unit and Integration tests.[^1] We will prioritize the use of well-supported, open-source tools to foster a collaborative development environment.

#### 2.1 Key Components

1.  **Unit Test Framework: Google Test (gtest)**
    *   **Description:** A feature-rich, open-source C++ test framework used to write and run unit tests, providing a structured syntax for defining tests and a rich set of assertion macros.[^5]
    *   **Justification:** Google Test is the industry standard for complex C++ projects. Its integrated mocking framework, Google Mock (gMock), is essential for isolating components and simulating dependencies, which is critical for testing the platform's stateful control software.[^6]

2.  **Hardware Abstraction & Mocking**
    *   **Description:** We will create a set of "mock" C++ classes that replicate the public interface of the real hardware driver classes. These mocks will not communicate with actual hardware; instead, they will record which of their methods were called, in what order, and with what parameters.
    *   **Justification:** This is the core strategy that enables software integration testing without physical hardware. It allows us to verify that the control software (e.g., the sequence interpreter) sends the correct sequence of commands to the hardware abstraction layer.[^7][^8]

3.  **Build & Automation System**
    *   **Description:** We will use CMake, an open-source build system, to manage the build process for both the main application and the test suite. A simple shell or Python script will serve as the test runner, orchestrating the build and execution steps.
    *   **Justification:** CMake is the de facto standard for cross-platform C++ projects and integrates well with Google Test. A simple script is sufficient for initial automation and provides a clear entry point for future CI/CD integration.[^3]

---

### 3. Implementation Plan (4-Day Schedule)

#### **Day 1: Foundation & Setup**
*   **Objective:** Establish a stable and repeatable build and test environment.
*   **Tasks:**
    1.  Set up the project structure, including separate directories for source code (`src`), test code (`tests`), and build outputs.
    2.  Configure the toolchain (compiler, linker).
    3.  Create the primary `CMakeLists.txt` file to build a placeholder application.
    4.  Integrate the Google Test framework into the CMake build system, preferably using `FetchContent` for automatic download and configuration.[^9]
    5.  Write a single "Hello World" unit test to verify that the framework is correctly configured, can be compiled, and executed successfully.

#### **Day 2: Unit Testing the Core Logic**
*   **Objective:** Validate the correctness of a critical, logic-heavy software component in isolation.
*   **System Under Test (SUT):** A core function within the system's **sequence interpretation tool**. Specifically, the logic that translates a high-level measurement recipe into a sequence of abstract hardware actions.
*   **Tasks:**
    1.  Identify a specific function or class in the sequence interpreter to test.
    2.  Refactor the code if necessary to allow its dependencies to be replaced by mocks (Dependency Injection).
    3.  Write a suite of unit tests using Google Test to cover various scenarios:
        *   Test with a standard, valid input recipe and assert that the correct sequence of actions is generated.
        *   Test with edge cases (e.g., an empty recipe).
        *   Test with invalid inputs and assert that appropriate errors are handled.

#### **Day 3: Hardware Mocking & Integration Testing**
*   **Objective:** Verify the interaction between the control logic (the sequence interpreter) and the hardware abstraction layer.
*   **Tasks:**
    1.  Define and implement mock classes for key hardware peripherals, such as `MockMotionAxis`, `MockShutter`, and `MockCamera`, using Google Mock (gMock).[^7][^8] These classes will share the same interface as the real hardware drivers.
    2.  Leverage Google Mock to set expectations on the sequence of function calls made to the mock objects.
    3.  Write a new software integration test suite.
    4.  In these tests, instantiate the real sequence interpreter component but provide it with instances of the mock hardware classes.
    5.  Execute a full "Move-Acquire-Measure" sequence through the sequence interpreter.
    6.  After execution, assert that the mock objects were called in the correct order (e.g., `move_to` was called before `open_shutter`).

#### **Day 4: Automation & Extensibility**
*   **Objective:** Turn the collection of tests into an automated, easy-to-use framework and document its usage for an open-source audience.
*   **Tasks:**
    1.  Create a top-level automation script (e.g., 'run_tests.sh') that orchestrates the build and test process using standard tools:
        *   Invokes CMake to configure the project (e.g., 'cmake -B build').
        *   Invokes the build tool via CMake to compile all targets (e.g., 'cmake --build build').
        *   Invokes the build tool via CMake to run the test suite (e.g., 'cmake --build build --target test').
        *   The script will check the exit code of each step and provide a final summary (e.g., "ALL TESTS PASSED" or "ERROR: Test failures detected").
    2.  Write a user-facing `README.md` file for the test framework (separate from this design document), explaining:
        *   The project's open-source goals.
        *   How to build and run the tests.
        *   How to add a new unit test.
        *   How to contribute to the project.
    3.  Clean up the code and add comments, specifically highlighting the extension points for future development.

---

### 4. Future Extensibility

This foundational framework is designed to grow through open collaboration. The following are clear next steps that can be built upon the work completed in these four days:

*   **CI/CD Integration:** The test automation script (e.g., `run_tests.sh`) can be directly called from a public CI/CD tool like GitLab CI or GitHub Actions to trigger automated testing on every code commit and pull request.[^3]
*   **Community Contributions:** The open and modular design will allow the community to contribute new mock hardware components, expand test coverage, and integrate with other open-source tools.
*   **Expanded Mock Capabilities:** The mock hardware can be enhanced to simulate error conditions (e.g., a motor failing to respond) or to return simulated sensor data, allowing for more robust testing of the control software's error handling and data processing logic.
*   **Static Analysis Integration:** Open-source static analysis tools can be added to the automation script to check for code quality and compliance with community standards before the unit tests are run.[^10]
*   **Path to Hardware-in-the-Loop (HIL):** The hardware abstraction layer provides the perfect seam for introducing HIL simulation. The mock objects can be replaced with components that communicate with a real-time HIL simulator, allowing the same control software to be tested against a high-fidelity virtual model of the physical system.[^2]

### 5. Conclusion

By the end of this focused four-day effort, we will have a lean, solid, and automated test framework. It will provide immediate value by verifying the core control logic of the metrology control software and will establish a scalable, open-source architecture ready for community-driven expansion into a comprehensive, enterprise-grade validation system.

### References

[^1] Martin Fowler, ["The Practical Test Pyramid"](https://martinfowler.com/articles/practical-test-pyramid.html), martinfowler.com, 2018.  
[^2] National Instruments, ["What Is Hardware-in-the-Loop (HIL) Testing?"](https://www.ni.com/en/innovations/white-papers/06/hardware-in-the-loop--hil--testing.html), ni.com, accessed October 2025.  
[^3] GitLab Documentation, ["CI/CD Pipelines"](https://docs.gitlab.com/ee/ci/pipelines/), docs.gitlab.com, accessed October 2025.  
[^4] Jenkins Project, ["Pipeline Syntax"](https://www.jenkins.io/doc/book/pipeline/syntax/), jenkins.io, accessed October 2025.  
[^5] Google, ["GoogleTest User’s Guide"](https://google.github.io/googletest), google.github.io, accessed October 2025.  
[^6] Google, ["gMock for dummies"](https://google.github.io/googletest/gmock_for_dummies.html), google.github.io, accessed October 2025.  
[^7] Gerard Meszaros, *xUnit Test Patterns: Refactoring Test Code*, Addison-Wesley, 2007.  
[^8] Vladimir Khorikov, *Unit Testing Principles, Practices, and Patterns*, Manning Publications, 2020.  
[^9] Craig Scott, *Professional CMake: A Practical Guide*, Crascit, 2023.  
[^10] SourceForge, ["Cppcheck – A tool for static C/C++ code analysis"](https://cppcheck.sourceforge.net), cppcheck.sourceforge.net, accessed October 2025.  
