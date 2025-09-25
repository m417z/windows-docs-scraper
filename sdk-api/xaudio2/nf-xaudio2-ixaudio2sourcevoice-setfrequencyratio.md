# IXAudio2SourceVoice::SetFrequencyRatio

## Description

Sets the frequency adjustment ratio of the voice.

## Parameters

### `Ratio` [in]

Frequency adjustment ratio. This value must be between XAUDIO2_MIN_FREQ_RATIO and the *MaxFrequencyRatio* parameter specified when the voice was created (see [IXAudio2::CreateSourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-createsourcevoice)). XAUDIO2_MIN_FREQ_RATIO currently is 0.0005, which allows pitch to be lowered by up to 11 octaves.

### `X2DEFAULT`

TBD

### `OperationSet` [in]

Identifies this call as part of a deferred batch. See the [XAudio2 Operation Sets](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-operation-sets) overview for more information.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of error codes.

## Remarks

Frequency adjustment is expressed as *source frequency* / *target frequency*. Changing the frequency ratio changes the rate audio is played on the voice. A ratio greater than 1.0 will cause the audio to play faster and a ratio less than 1.0 will cause the audio to play slower. Additionally, the frequency ratio affects the pitch of audio on the voice. As an example, a value of 1.0 has no effect on the audio, whereas a value of 2.0 raises pitch by one octave and 0.5 lowers it by one octave.

If **SetFrequencyRatio** is called specifying a Ratio value outside the valid range, the method will set the frequency ratio to the nearest valid value. A warning also will be generated for debug builds.

**Note** [IXAudio2SourceVoice::GetFrequencyRatio](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-getfrequencyratio) always returns the voice's actual current frequency ratio. However, this may not match the ratio set by the most recent **IXAudio2SourceVoice::SetFrequencyRatio** call: the actual ratio is only changed the next time the audio engine runs after the **IXAudio2SourceVoice::SetFrequencyRatio** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if **IXAudio2SourceVoice::SetFrequencyRatio** was called with a deferred operation ID).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Change Voice Pitch](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--change-voice-pitch)

[IXAudio2SourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2sourcevoice)