# IAudioProcessingObjectRT::CalcOutputFrames

## Description

The `CalcOutputFrames` method returns the number of output frames that an APO requires for a given number of input frames.

## Parameters

### `u32InputFrameCount` [in]

This is a count of the number of input frames.

## Return value

The `CalcOutputFrames` method returns the number of output frames that an APO will generate for a given number of input frames.

| Return code | Description |
| --- | --- |

## Remarks

The `CalcOutputFrames` method can be called form a real-time processing thread. The implementation of this method must not block or touch paged memory and it should not call any system blocking routines.