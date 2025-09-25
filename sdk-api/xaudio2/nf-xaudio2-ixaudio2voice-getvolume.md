# IXAudio2Voice::GetVolume

## Description

Gets the current overall volume level of the voice.

## Parameters

### `pVolume` [out]

Returns the current overall volume level of the voice. See Remarks for more information on volume levels.

## Return value

This method does not return a value.

## Remarks

Volume levels are expressed as floating-point amplitude multipliers between -224 to 224, with a maximum gain of 144.5 dB. A volume level of 1 means there is no attenuation or gain and 0 means silence. Negative levels can be used to invert the audio's phase. See [XAudio2 Volume and Pitch Control](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-volume-and-pitch-control) for additional information on volume control.

**Note** **GetVolume** always returns the volume most recently set by [IXAudio2Voice::SetVolume](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setvolume). However, it may not actually be in effect yet: it only takes effect the next time the audio engine runs after the **IXAudio2Voice::SetVolume** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if **IXAudio2Voice::SetVolume** was called with a deferred operation ID).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)