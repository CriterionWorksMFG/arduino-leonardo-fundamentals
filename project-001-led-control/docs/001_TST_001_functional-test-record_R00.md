# Project 001 — Functional Test Record

**Criterion Works | Engineering Portfolio**  
Document: 001_TST_001 | Revision: R00 | Prepared: 2026-11-26

## Evidence and scope
Retrospective record of developer-reported operation during original development and static inspection of the retained final sketch. No new hardware tests were performed. Individual test IDs are assigned retrospectively; original dates and instrument readings are unavailable.

| ID | Functional check | Expected behavior from source | Evidence / disposition |
|---|---|---|---|
| T001 | Basic LED output | Onboard LED changes state | Developer reported working |
| T002 | Command 0 | LED remains LOW | Developer reported working |
| T003 | Command 1 | 1000 ms ON / 1000 ms OFF | Developer reported mode working; timing not measured |
| T004 | Command 2 | 100 ms ON / 100 ms OFF | Developer reported mode working; timing not measured |
| T005 | Command 3 | 500 ms ON / 1500 ms OFF | Developer reported mode working; timing not measured |
| T006 | Command 4 | 50 ms ON / 950 ms OFF | Developer reported mode working; timing not measured |
| T007 | Serial mode selection | Commands 0–4 select modes | Developer reported all five modes responding |
| T008 | Non-blocking operation | Timing uses millis(), no delay() calls in final sketch | Static inspection confirms implementation; latency not measured |

## Repeatable verification procedure (proposed, not executed)
1. Connect Arduino Leonardo via USB, select the board and port in Arduino IDE, compile and upload the final sketch.
2. Open Serial Monitor with 9600 selected; verify startup LED is off.
3. Send each command 0–4 and observe behavior and serial acknowledgement. The startup prompt omits command 4.
4. While Normal mode is active, send 0 and observe the response; record latency if measured.
5. If instrumentation is available, measure ON/OFF intervals and record actual values and acceptance tolerances before claiming timing validation.
6. Record date, hardware, firmware revision, observations and any failures.

## Disposition
Developer-reported functional operation; formal retest, compilation during this review, measured timing and independent validation remain outstanding. No safety-rated function is claimed.

## Revision history
R00 — Initial retrospective test record.
