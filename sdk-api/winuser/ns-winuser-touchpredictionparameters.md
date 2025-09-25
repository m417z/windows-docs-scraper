# TOUCHPREDICTIONPARAMETERS structure

## Description

Contains hardware input details that can be used to predict touch targets and help compensate for hardware latency when processing touch and gesture input that contains distance and velocity data.

## Members

### `cbSize`

The size of this structure, in bytes.

### `dwLatency`

Latency in milliseconds.

### `dwSampleTime`

Sample time in milliseconds (used to calculate velocity).

### `bUseHWTimeStamp`

Use timestamps provided by the hardware.

## Remarks

By default, touch prediction is activated. For information on getting pointer data without deactivating touch prediction, see [GetUnpredictedMessagePos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getunpredictedmessagepos).

## See also

[Structures](https://learn.microsoft.com/windows/win32/inputmsg/structures)