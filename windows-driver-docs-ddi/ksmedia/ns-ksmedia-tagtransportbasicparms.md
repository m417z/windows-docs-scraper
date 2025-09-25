## Description

The TRANSPORTBASICPARMS structure is defined but not used.

## Members

### `TimeFormat`

Indicates the basic time format.

| Flag | Meaning |
|---|---|
| ED_FORMAT_MILLISECONDS | Milliseconds |
| ED_FORMAT_FRAMES | Frames |
| ED_FORMAT_REFERENCE_TIME | Reference time |
| ED_FORMAT_HMSF | Binary coded decimal, representing hours, minutes, seconds, and frames |
| ED_FORMAT_TMSF | Binary coded decimal, representing tracks, minutes, seconds, and frames |

### `TimeReference`

Indicates the basic time reference.

| Flag | Meaning |
|---|---|
| ED_TIMEREF_TIMECODE | Time code |
| ED_TIMEREF_CONTROL_TRACK | Control track |
| ED_TIMEREF_INDEX | Index |

### `Superimpose`

Indicates whether to enable or disable the onscreen display. Specify **TRUE** to enable, **FALSE** to disable.

### `EndStopAction`

Specifies the stop action.

| Flag | Meaning |
|---|---|
| ED_MODE_STOP | Stop |
| ED_MODE_REWIND | Rewind |
| ED_MODE_FREEZE | Freeze/pause |

### `RecordFormat`

Indicates the basic record format.

| Flag | Meaning |
|---|---|
| ED_RECORD_FORMAT_SP | Standard play |
| ED_RECORD_FORMAT_LP | Long play |
| ED_RECORD_FORMAT_EP | Extended play |

### `StepFrames`

Indicates the frame step count.

### `SetpField`

Indicates the field step count.

### `Preroll`

Indicates the preroll amount.

### `RecPreroll`

Indicates the record preroll amount.

### `Postroll`

Indicates the postroll amount.

### `EditDelay`

Indicates the edit delay amount.

### `PlayTCDelay`

Indicates the play timecode delay amount.

### `RecTCDelay`

Indicates the record timecode delay amount.

### `EditField`

Indicates the edit field.

### `FrameServo`

Specifies the frame servo.

### `ColorFrameServo`

Specifies the color frame servo.

### `ServoRef`

Specifies the servo ref.

| Flag | Meaning |
|---|---|
| ED_REF_EXTERNAL | External |
| ED_REF_INPUT | Input |
| ED_REF_INTERNAL | Internal |
| ED_REF_AUTO | Auto |

### `WarnGenlock`

Indicates the warn genlock.

### `SetTracking`

Specifies the tracking.

| Flag | Meaning |
|---|---|
| ED_TRACKING_PLUS | Plus |
| ED_TRACKING_MINUS | Minus |
| ED_TRACKING_RESET | Reset |

### `VolumeName`

Specifies the volume name.

### `Ballistic`

Specifies any proprietary data.

### `Speed`

Specifies the speed.

### `CounterFormat`

Specifies the counter format.

### `TunerChannel`

Indicates the tuner channel.

### `TunerNumber`

Indicates the tuner number.

### `TimerEvent`

Specifies a timer event.

### `TimerStartDay`

Indicates the timer start-day.

### `TimerStartTime`

Indicates the timer start-time.

### `TimerStopDay`

Indicates the timer stop-day.

### `TimerStopTime`

Indicates the timer stop-time.

## Remarks

Any ED_*Xxx* tokens are defined in *xprtdefs.h* in the Microsoft DirectX SDK.