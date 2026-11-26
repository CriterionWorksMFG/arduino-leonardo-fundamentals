
# Project 001 — LED Control System

**Criterion Works | Engineering Portfolio**

| Project Information | Details |
|---|---|
| Project ID | 001 |
| Platform | Arduino Leonardo |
| Discipline | Electronics and Embedded Systems |
| Development Status | Completed |
| Completion Date | November 20, 2026 |
| Documentation Revision | R00 |

## 1. Project Overview

This project implements a programmable LED control system using the Arduino Leonardo microcontroller.

The system progressed from basic digital output control to a multi-mode, serial-controlled application utilizing non-blocking timing.

The completed application allows the operator to select between five operating modes through the Arduino Serial Monitor.

## 2. Engineering Objectives

- Establish foundational microcontroller programming skills.
- Implement digital output control.
- Implement serial command processing.
- Develop multiple operating modes.
- Transition from blocking delays to non-blocking timing.
- Implement a heartbeat status indicator.
- Verify functional operation across all five modes.

## 3. Hardware and Software

| Component | Specification | Quantity |
|---|---|---:|
| Microcontroller | Arduino Leonardo | 1 |
| Indicator | Integrated onboard LED | 1 |
| Communication and Power | USB cable | 1 |
| Development Environment | Arduino IDE | N/A |
| Programming Language | Arduino C/C++ | N/A |

The system utilizes the onboard LED through the LED_BUILTIN pin definition.

## 4. System Architecture

The system consists of four primary functional elements:

1. Operator command through the Serial Monitor.
2. Serial command interpretation.
3. Operating mode and timing logic.
4. Digital LED output.

The microcontroller processes incoming serial commands and adjusts the LED output according to the selected operating mode.

## 5. Operating Modes

| Command | Operating Mode | ON Duration | OFF Duration |
|---|---|---:|---:|
| 0 | Stop | OFF | Continuous |
| 1 | Normal | 1000 ms | 1000 ms |
| 2 | Warning | 100 ms | 100 ms |
| 3 | Custom | 500 ms | 1500 ms |
| 4 | Heartbeat | 50 ms | 950 ms |

Serial communication operates at 9600 baud.

## 6. Development Progression

The project was developed incrementally through the following stages:

1. Basic LED blinking.
2. Double-flash LED operation.
3. Multiple operating modes.
4. Serial-based mode selection.
5. Additional custom operating mode.
6. Non-blocking timing and heartbeat functionality.

## 7. Engineering Design Decisions

### Blocking versus Non-Blocking Timing

Initial development utilized delay-based timing to establish basic LED operation.

The application was subsequently transitioned to millis()-based timing to allow the microcontroller to continue processing serial commands while controlling LED timing.

This approach establishes a foundation for more complex embedded control applications requiring concurrent processing of inputs and outputs.

### Serial-Based Control

Serial communication was implemented to allow operating mode selection without modifying and uploading the application for each mode change.

### Heartbeat Indication

A short, periodic LED pulse was implemented as a basic visual indication of controller activity.

## 8. Functional Testing

| Test ID | Test Description | Reported Result |
|---|---|---|
| T001 | Basic LED output operation | Pass |
| T002 | Stop mode operation | Pass |
| T003 | Normal mode operation | Pass |
| T004 | Warning mode operation | Pass |
| T005 | Custom mode operation | Pass |
| T006 | Heartbeat mode operation | Pass |
| T007 | Serial-based mode selection | Pass |
| T008 | Non-blocking LED timing | Pass |

All five operating modes were reported functional during hands-on development.

Results are based on development observations. Independent timing measurements and formal instrument-based validation were not documented.

## 9. Skills Practiced

- Microcontroller programming
- Digital output control
- Conditional logic
- Variable management
- Serial communication
- Operating mode management
- Non-blocking timing
- Functional testing
- Incremental software development

## 10. Lessons Learned

- Blocking delays can limit controller responsiveness.
- Non-blocking timing allows additional logic to execute while timed operations are active.
- Serial communication provides a practical interface for testing embedded applications.
- Incremental development simplifies functional testing and troubleshooting.
- Status indicators provide useful visual feedback during controller operation.

## 11. Future Improvements

Potential improvements include:

- Physical push-button control.
- Additional digital outputs.
- Expanded diagnostic feedback.
- Hardware-based fault indication.
- Instrument-based timing verification.

These improvements are outside the completed scope of Project 001.

## 12. Documentation Limitations

Original photographs were not retained during development.

This documentation was reconstructed from the original development records. Final source code verification and supporting technical documentation remain pending.

No unrecorded measurements or test results are claimed.

## 13. Revision History

| Revision | Description |
|---|---|
| R00 | Initial retrospective engineering documentation |

---

**Criterion Works — Engineering Portfolio**
