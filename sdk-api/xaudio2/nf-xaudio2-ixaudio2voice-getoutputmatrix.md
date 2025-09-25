# IXAudio2Voice::GetOutputMatrix

## Description

Gets the volume level of each channel of the final output for the voice. These channels are mapped to the input channels of a specified destination voice.

## Parameters

### `pDestinationVoice` [in]

Pointer specifying the destination [IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice) to retrieve the output matrix for.

**Note** If the voice sends to a single target voice then specifying NULL will cause **GetOutputMatrix** to operate on that target voice.

### `SourceChannels` [in]

Confirms the output channel count of the voice. This is the number of channels that are produced by the last effect in the chain.

### `DestinationChannels` [in]

Confirms the input channel count of the destination voice.

### `pLevelMatrix` [out]

Array of [*SourceChannels* * *DestinationChannels*] volume levels sent to the destination voice. The level sent from source channel S to destination channel D is returned in the form *pLevelMatrix*[*DestinationChannels* × S + D]. See Remarks for more information on volume levels.

## Return value

This method does not return a value.

## Remarks

This method applies only to source and submix voices, because mastering voices write directly to the device with no matrix mixing.

Volume levels are expressed as floating-point amplitude multipliers between -2²⁴ to 2²⁴, with a maximum gain of 144.5 dB. A volume level of 1 means there is no attenuation or gain and 0 means silence. Negative levels can be used to invert the audio's phase. See [XAudio2 Volume and Pitch Control](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-volume-and-pitch-control) for additional information on volume control.

See [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-waveformatextensible) for information on standard channel ordering.

**Note** **GetOutputMatrix** always returns the levels most recently set by [IXAudio2Voice::SetOutputMatrix](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setoutputmatrix). However, they may not actually be in effect yet: they only take effect the next time the audio engine runs after the **IXAudio2Voice::SetOutputMatrix** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if **IXAudio2Voice::SetOutputMatrix** was called with a deferred operation ID).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)