# IAudioProcessingObjectRT::CalcInputFrames

## Description

The `CalcInputFrames` method returns the number of input frames that an APO requires to generate a given number of output frames.

## Parameters

### `u32OutputFrameCount`

This is a count of the number of output frames.

## Return value

The `CalcInputFrames` method returns the number of input frames that are required to generate the given number of output frames.

| Return code | Description |
| --- | --- |

## Remarks

The `CalcInputFrames` method is called from a real-time processing thread. The implementation of this method must not touch paged memory and it should not call any system blocking routines.