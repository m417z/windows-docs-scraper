# IXAudio2SourceVoice::Start

## Description

Starts consumption and processing of audio by the voice. Delivers the result to any connected submix or mastering voices, or to the output device.

## Parameters

### `X2DEFAULT`

TBD

### `Flags` [in]

Flags that control how the voice is started. Must be 0.

### `OperationSet` [in]

Identifies this call as part of a deferred batch. See the [XAudio2 Operation Sets](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-operation-sets) overview for more information.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

If the XAudio2 engine is stopped, the voice stops running. However, it remains in the started state, so that it starts running again as soon as the engine starts.

When first created, source voices are in the stopped state. Submix and mastering voices are in the started state.

After **Start** is called it has no further effect if called again before [IXAudio2SourceVoice::Stop](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-stop) is called. In addition multiple calls to **Start** without matching calls to **IXAudio2SourceVoice::Stop** will result in warning messages in debug builds.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Build a Basic Audio Processing Graph](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--build-a-basic-audio-processing-graph)

[How to: Stream a Sound from Disk](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--stream-a-sound-from-disk)

[IXAudio2SourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2sourcevoice)

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)