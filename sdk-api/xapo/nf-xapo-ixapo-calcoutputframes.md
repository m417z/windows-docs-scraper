# IXAPO::CalcOutputFrames

## Description

Returns the number of output frames that will be generated from a given number of input frames.

## Parameters

### `InputFrameCount`

The number of input frames.

## Return value

Returns the number of output frames that will be produced.

## Remarks

XAudio2 calls this method to determine how large of an output buffer an XAPO will require for a certain number of input frames. **CalcOutputFrames** is only called by XAudio2 if the XAPO is locked.

This function should not block, because it may be called from the realtime audio processing thread.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo)