# IXAudio2SourceVoice::GetState

## Description

Returns the voice's current cursor position data.

## Parameters

### `pVoiceState`

Pointer to an [XAUDIO2_VOICE_STATE](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_voice_state) structure containing the state of the voice.

### `X2DEFAULT`

TBD

### `Flags` [optional]

Flags controlling which voice state data should be returned. Valid values are 0 or **XAUDIO2_VOICE_NOSAMPLESPLAYED**. The default value is 0. If you specify **XAUDIO2_VOICE_NOSAMPLESPLAYED**, **GetState** returns only the buffer state, not the sampler state. **GetState** takes roughly one-third as much time to complete when you specify
**XAUDIO2_VOICE_NOSAMPLESPLAYED**.

## Remarks

If a client needs to get the correlated positions of several voices (for example, to know exactly which sample of a given voice is playing when a given sample of another voice is playing), it must make **GetState** calls in an XAudio2 engine callback. This ensures that none of the voices advance while the calls are being made. See the [XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks) overview for information about using XAudio2 callbacks.

Note that the DirectX SDK versions of XAUDIO2 do not take the Flags parameter for **GetState**.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Stream a Sound from Disk](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--stream-a-sound-from-disk)

[IXAudio2SourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2sourcevoice)