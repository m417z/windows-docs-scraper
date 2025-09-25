# IXAudio2Voice::GetFilterParameters

## Description

Gets the voice's filter parameters.

## Parameters

### `pParameters` [out]

Pointer to an [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters) structure containing the filter information.

## Return value

This method does not return a value.

## Remarks

**GetFilterParameters** will fail if the voice was not created with the XAUDIO2_VOICE_USEFILTER flag.

**GetFilterParameters** always returns this voice's actual current filter parameters. However, these may not match the parameters set by the most recent [IXAudio2Voice::SetFilterParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setfilterparameters) call: the actual parameters are only changed the next time the audio engine runs after the **IXAudio2Voice::SetFilterParameters** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if **IXAudio2Voice::SetFilterParameters** was called with a deferred operation ID).

**Note** **GetFilterParameters** is usable only on source and submix voices and has no effect on mastering voices.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)