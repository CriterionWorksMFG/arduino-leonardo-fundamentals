# Static source review — Project 002

Revision R00. Original files preserved byte-for-byte. No compilation or hardware execution performed.

| File | SHA-256 |
|---|---|
| `Project002_Challenge1.ino` | `c66ac97e79398c7cedd8d4fb34619ea276bedf19d97d0450848a183a926b9837` |
| `Project002_Challenge2_Button.ino` | `1763934f29688d6b62bba5daebb2e141436aa8758718f99d9a74c8885899425e` |
| `Project003_Challenge3_Toggle.ino` | `6d8865be9db11027ab8d7fbb9572638d701226b4dcabfec9cd1175ab1dd121f2` |
| `Project002_Challenge4_ControlPanel.ino` | `adb16bf4d640590324aa7013d80665c8c4e6396f46c5279fc5f603f2e8ca1d39` |
| `Project002_Challenge4_LED_Tested.ino` | `33f7704fbc1d9d2368bf700eb6d816809394304633d486978b577999aa50435e` |
| `Project002_Challenge5_AutomaticSignals.ino` | `221ddb3b1cb69e4b90e7223693eb9cafcf858c2f0ec12cccceca4f284c5781bd` |
| `Project002_Challenge6_FaultDetection.ino` | `2544c1f13aebf2b4d93b4bfa3d0589b912893e0560f85f9f76b3e271ae6dc7d0` |

## Findings
- Challenge 1: D8 toggles using 500 ms blocking delays.
- Challenge 2: D2 uses INPUT_PULLUP; D8 follows active-low button.
- Toggle sketch: 50 ms debounce threshold (strictly greater than 50 ms), press-edge toggle, serial status.
- Challenge 4 control panel: two independent debounce trackers, three states and stop latch.
- Challenge 4 LED test: four output combinations with 1000 ms delays.
- Challenge 5: warning LED toggles every 200 ms, normal green steady.
- Challenge 6: four states, 50 ms debounce (greater than or equal), uppercase F/R, fault priority and reset to STOP.
- Final sketch does not reset blink timestamp/phase on mode changes; first pulse may differ from steady-state nominal timing. Invalid serial bytes ignored. Both-button stop does not override active simulated fault. Reset latch clears once both debounced inputs are HIGH, including in the reset iteration if already released. No physical fault sensor or safety-rated stop.
- Toggle filename uses Project003; retained as received and classified by content and prior development context.
- No obvious credentials or sensitive identifiers found in the sketches.
