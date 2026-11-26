# Functional test record — Project 002
Revision R00. Retrospective record. Results are developer-reported at development-stage level; proposed repeat procedures below have not been executed in this review.

| ID | Proposed repeat procedure | Expected result | Evidence status |
|---|---|---|---|
| T001 | Run Challenge 1 | D8 toggles every 500 ms | Original development reported working |
| T002 | Run Challenge 2, press/release D2 | LED follows button | Original development reported working |
| T003 | Run toggle sketch; press twice | LED toggles once per stable press | Developer-reported pass |
| T004 | Run final sketch; press D2, then D3 | Warning then normal | Developer-reported signaling; exact final-sketch sequence not independently verified |
| T005 | Hold both buttons, release one then both | Stop until release and new press | Developer-reported stop latch |
| T006 | Send F in normal or warning; press buttons | Fault red blinking, button commands overridden | Developer-reported fault override |
| T007 | Send R while fault active | Stop; new press after release permits restart | Developer-reported reset |
| T008 | Measure steady-state red transitions | 200 ms warning, 500 ms fault nominal | Not measured |
| T009 | Compile final sketch for Leonardo | Successful compilation | Not performed in review |

No test dates, instrument readings or formal acceptance results are inferred. Simulated fault functionality is not a safety validation.
