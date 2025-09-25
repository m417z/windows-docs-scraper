# IXAudio2SourceVoice::GetFrequencyRatio

## Description

Returns the frequency adjustment ratio of the voice.

## Parameters

### `pRatio` [out]

Returns the current frequency adjustment ratio if successful.

## Remarks

**GetFrequencyRatio** always returns the voice's actual current frequency ratio. However, this may not match the ratio set by the most recent [IXAudio2SourceVoice::SetFrequencyRatio](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-setfrequencyratio) call: the actual ratio is only changed the next time the audio engine runs after the **IXAudio2SourceVoice::SetFrequencyRatio** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if **IXAudio2SourceVoice::SetFrequencyRatio** was called with a deferred operation ID).

For information on frequency ratios, see [IXAudio2SourceVoice::SetFrequencyRatio](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-setfrequencyratio).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2SourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2sourcevoice)