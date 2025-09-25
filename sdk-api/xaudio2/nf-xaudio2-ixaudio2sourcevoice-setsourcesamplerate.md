# IXAudio2SourceVoice::SetSourceSampleRate

## Description

Reconfigures the voice to consume source data at a different sample rate than the rate specified when the voice was created.

## Parameters

### `NewSourceSampleRate` [in]

The new sample rate the voice should process submitted data at. Valid sample rates are 1kHz to 200kHz.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of error codes.

## Remarks

The **SetSourceSampleRate** method supports reuse of XAudio2 voices by allowing a voice to play sounds with a variety of sample rates. To use **SetSourceSampleRate** the voice must have been created without the XAUDIO2_VOICE_NOPITCH or XAUDIO2_VOICE_NOSRC flags and must not have any buffers currently queued.

The typical use of **SetSourceSampleRate** is to support voice pooling. For example to support voice pooling an application would precreate all the voices it expects to use. Whenever a new sound will be played the application chooses an inactive voice or ,if all voices are busy, picks the least important voice and calls **SetSourceSampleRate** on the voice with the new sound's sample rate. After **SetSourceSampleRate** has been called on the voice, the application can immediately start submitting and playing buffers with the new sample rate. This allows the application to avoid the overhead of creating and destroying voices frequently during gameplay.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2SourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2sourcevoice)