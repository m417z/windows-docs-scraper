# IXAPO::CalcInputFrames

## Description

Returns the number of input frames required to generate the given number of output frames.

## Parameters

### `OutputFrameCount`

The number of output frames desired.

## Return value

Returns the number of input frames required.

## Remarks

XAudio2 calls this method to determine what size input buffer an XAPO requires to generate the given number of output frames. This method only needs to be called once while an XAPO is locked. **CalcInputFrames** is only called by XAudio2 if the XAPO is locked.

This function should not block, because it may be called from the realtime audio processing thread.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo)