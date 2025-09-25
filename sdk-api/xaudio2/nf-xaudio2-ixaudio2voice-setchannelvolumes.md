# IXAudio2Voice::SetChannelVolumes

## Description

Sets the volume levels for the voice, per channel.

## Parameters

### `Channels` [in]

Number of channels in the voice.

### `pVolumes` [in]

Array containing the new volumes of each channel in the voice. The array must have *Channels* elements. See Remarks for more information on volume levels.

### `X2DEFAULT`

TBD

### `OperationSet` [in]

Identifies this call as part of a deferred batch. See the [XAudio2 Operation Sets](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-operation-sets) overview for more information.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

**SetChannelVolumes** controls a voice's per-channel output levels and is applied just after the voice's final SRC and before its sends.

This method is valid only for source and submix voices, because mastering voices do not specify volume per channel.

Volume levels are expressed as floating-point amplitude multipliers between -XAUDIO2_MAX_VOLUME_LEVEL and XAUDIO2_MAX_VOLUME_LEVEL (-2²⁴ to 2²⁴), with a maximum gain of 144.5 dB. A volume of 1 means there is no attenuation or gain and 0 means silence. Negative levels can be used to invert the audio's phase. See [XAudio2 Volume and Pitch Control](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-volume-and-pitch-control) for additional information on volume control.

**Note** [IXAudio2Voice::GetChannelVolumes](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-getchannelvolumes) always returns the volume levels most recently set by **IXAudio2Voice::SetChannelVolumes**. However, those values may not actually be in effect yet: they only take effect the next time the audio engine runs after the **IXAudio2Voice::SetChannelVolumes** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if **IXAudio2Voice::SetChannelVolumes** was called with a deferred operation ID).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Change Voice Volume](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--change-voice-volume)

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)