# IAudioClient::GetBufferSize

## Description

The **GetBufferSize** method retrieves the size (maximum capacity) of the endpoint buffer.

## Parameters

### `pNumBufferFrames` [out]

Pointer to a **UINT32** variable into which the method writes the number of audio frames that the buffer can hold.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_NOT_INITIALIZED** | The audio stream has not been successfully initialized. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |
| **E_POINTER** | Parameter *pNumBufferFrames* is **NULL**. |

## Remarks

This method requires prior initialization of the [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) interface. All calls to this method will fail with the error AUDCLNT_E_NOT_INITIALIZED until the client initializes the audio stream by successfully calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method.

This method retrieves the length of the endpoint buffer shared between the client application and the audio engine. The length is expressed as the number of audio frames the buffer can hold. The size in bytes of an audio frame is calculated as the number of channels in the stream multiplied by the sample size per channel. For example, the frame size is four bytes for a stereo (2-channel) stream with 16-bit samples.

The [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method allocates the buffer. The client specifies the buffer length in the *hnsBufferDuration* parameter value that it passes to the **Initialize** method. For rendering clients, the buffer length determines the maximum amount of rendering data that the application can write to the endpoint buffer during a single processing pass. For capture clients, the buffer length determines the maximum amount of capture data that the audio engine can read from the endpoint buffer during a single processing pass. The client should always call **GetBufferSize** after calling **Initialize** to determine the actual size of the allocated buffer, which might differ from the requested size.

Rendering clients can use this value to calculate the largest rendering buffer size that can be requested from [IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) during each processing pass.

For code examples that call the **GetBufferSize** method, see the following topics:

* [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream)
* [Capturing a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/capturing-a-stream)

## See also

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer)