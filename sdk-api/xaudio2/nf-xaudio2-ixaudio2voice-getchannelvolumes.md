# IXAudio2Voice::GetChannelVolumes

## Description

Returns the volume levels for the voice, per channel.

## Parameters

### `Channels` [in]

Confirms the channel count of the voice.

### `pVolumes` [out]

Returns the current volume level of each channel in the voice. The array must have at least *Channels* elements. See Remarks for more information on volume levels.

## Return value

This method does not return a value.

## Remarks

These settings are applied after the effect chain is applied. This method is valid only for source and submix voices, because mastering voices do not specify volume per channel.

Volume levels are expressed as floating-point amplitude multipliers between -2²⁴ to 2²⁴, with a maximum gain of 144.5 dB. A volume of 1 means there is no attenuation or gain, 0 means silence, and negative levels can be used to invert the audio's phase. See [XAudio2 Volume and Pitch Control](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-volume-and-pitch-control) for additional information on volume control.

**Note** **GetChannelVolumes** always returns the volume levels most recently set by [IXAudio2Voice::SetChannelVolumes](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setchannelvolumes). However, those values may not actually be in effect yet: they only take effect the next time the audio engine runs after the **IXAudio2Voice::SetChannelVolumes** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if **IXAudio2Voice::SetChannelVolumes** was called with a deferred operation ID).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)