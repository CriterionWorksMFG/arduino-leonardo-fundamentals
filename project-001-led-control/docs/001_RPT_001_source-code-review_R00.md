# Project 001 — Source Code Review Record

**Criterion Works | Engineering Portfolio**  
Document: 001_RPT_001 | Revision: R00 | Reviewed: 2026-11-26

## Scope
Static inspection of all four original Arduino sketches. No compilation or hardware execution was performed during review.

| Sketch | Observed implementation |
|---|---|
| Challenge 4 | Serial commands 0–3, blocking delay-based timing; custom mode 500 ms ON / 500 ms OFF |
| Challenge 5 | LED state toggles at a configured 250 ms interval using millis() |
| Challenge 6 | Five serial-controlled modes, unsigned elapsed-time arithmetic, independent ON/OFF intervals |
| Final controller | Same implementation as Challenge 6; primary application |

## Final controller findings
- Uses LED_BUILTIN, explicitly initializes LED LOW and mode 0.
- Calls Serial.begin(9600); accepts ASCII digits 0–4.
- Valid commands reset previousMillis and set LED LOW for Stop or HIGH otherwise.
- Active modes select the interval from onTime or offTime and toggle when elapsed time reaches that interval.
- Configured ON/OFF intervals: Normal 1000/1000 ms; Warning 100/100 ms; Custom 500/1500 ms; Heartbeat 50/950 ms. Stop stays off.
- No delay() calls in final sketch. Serial printing can still affect execution timing; deterministic latency is not established.

## Findings and disposition
| ID | Finding | Disposition |
|---|---|---|
| F01 | Challenge 4 startup prompt omits command 3 | Retain original; document |
| F02 | Challenge 6 and final startup prompts omit command 4 | Retain original; document |
| F03 | Challenge 6 and final sketch are byte-identical | Preserve both for provenance |
| F04 | Invalid characters are ignored without an error message | Document as limitation |
| F05 | No measured timing or compile evidence from this review | Do not claim independent validation |

No obvious credentials or personal identifiers were found in the four sketch contents. This is not a repository-wide security review.

## Original file integrity (SHA-256)

- `Project001_Challenge4.ino`: `49cc3942c4a76d3045387cb9d95762017016981aaff74117612cdd0d29d7677e`

- `Project001_Challenge5.ino`: `4b1f6718789e4ca6a7a5d96403cfd1b48b1b255f51a079dd8bb501430ac13fc8`

- `Project001_Challenge6.ino`: `5ad33303ac608fab2292e6aefbc66793638c5b3429157e3c9a1bc9620a168198`

- `Project001_Final_5Mode_Controller.ino`: `5ad33303ac608fab2292e6aefbc66793638c5b3429157e3c9a1bc9620a168198`

## Revision history
R00 — Initial static review record.
