# IXAudio2Voice::GetOutputFilterParameters

## Description

Returns the filter parameters from one of this voice's sends.

## Parameters

### `pDestinationVoice` [in]

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice) pointer to the destination voice of the send whose filter parameters will be read.

### `pParameters` [out]

Pointer to an [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters) structure containing the filter information.

## Return value

This method does not return a value.

## Remarks

**GetOutputFilterParameters** will fail if the send was not created with the XAUDIO2_SEND_USEFILTER flag. This method is usable only on sends belonging to source and submix voices and has no effect on mastering voices’ sends.

**Note** **IXAudio2Voice::GetOutputFilterParameters** always returns this send’s actual current filter parameters. However, these may not match the parameters set by the most recent [IXAudio2Voice::SetOutputFilterParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setoutputfilterparameters) call: the actual parameters are only changed the next time the audio engine runs after the **IXAudio2Voice::SetOutputFilterParameters** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if **IXAudio2Voice::SetOutputFilterParameters** was called with a deferred operation ID).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)