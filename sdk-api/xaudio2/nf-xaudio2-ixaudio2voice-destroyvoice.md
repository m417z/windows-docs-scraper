# IXAudio2Voice::DestroyVoice

## Description

Destroys the voice. If necessary, stops the voice and removes it from the XAudio2 graph.

## Return value

This method does not return a value.

## Remarks

If any other voice is currently sending audio to this voice, the method fails.

**DestroyVoice** waits for the audio processing thread to be idle, so it can take a little while (typically no more than a couple of milliseconds). This is necessary to guarantee that the voice will no longer make any callbacks or read any audio data, so the application can safely free up these resources as soon as the call returns.

To avoid title thread interruptions from a blocking **DestroyVoice** call, the application can destroy voices on a separate non-critical thread, or the application can use voice pooling strategies to reuse voices rather than destroying them. Note that voices can only be reused with audio that has the same data format and the same number of channels the voice was created with. A voice can play audio data with different sample rates than that of the voice by calling [IXAudio2SourceVoice::SetFrequencyRatio](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-setfrequencyratio) with an appropriate ratio parameter.

It is invalid to call **DestroyVoice** from within a callback (that is, [IXAudio2EngineCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2enginecallback) or [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)).

### Platform Requirements

Windows 10 (XAudio2.9);
Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)