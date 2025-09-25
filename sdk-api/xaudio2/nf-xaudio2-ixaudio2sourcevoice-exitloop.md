# IXAudio2SourceVoice::ExitLoop

## Description

Stops looping the voice when it reaches the end of the current loop region.

## Parameters

### `X2DEFAULT` [in]

Identifies this call as part of a deferred batch. See the [XAudio2 Operation Sets](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-operation-sets) overview for more information.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

If the cursor for the voice is not in a loop region, **ExitLoop** does nothing.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2SourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2sourcevoice)