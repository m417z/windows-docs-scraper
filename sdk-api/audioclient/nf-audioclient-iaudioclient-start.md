# IAudioClient::Start

## Description

The **Start** method starts the audio stream.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_NOT_INITIALIZED** | The audio stream has not been successfully initialized. |
| **AUDCLNT_E_NOT_STOPPED** | The audio stream was not stopped at the time of the [Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start) call. |
| **AUDCLNT_E_EVENTHANDLE_NOT_SET** | The audio stream is configured to use event-driven buffering, but the caller has not called [IAudioClient::SetEventHandle](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-seteventhandle) to set the event handle on the stream. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method requires prior initialization of the [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) interface. All calls to this method will fail with the error AUDCLNT_E_NOT_INITIALIZED until the client initializes the audio stream by successfully calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method.

**Start** is a control method that the client calls to start the audio stream. Starting the stream causes the [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) object to begin streaming data between the endpoint buffer and the audio engine. It also causes the stream's audio clock to resume counting from its current position.

The first time this method is called following initialization of the stream, the [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) object's stream position counter begins at 0. Otherwise, the clock resumes from its position at the time that the stream was last stopped. Resetting the stream forces the stream position back to 0.

To avoid start-up glitches with rendering streams, clients should not call **Start** until the audio engine has been initially loaded with data by calling the [IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) and [IAudioRenderClient::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-releasebuffer) methods on the rendering interface.

For code examples that call the **Start** method, see the following topics:

* [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream)
* [Capturing a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/capturing-a-stream)

## See also

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer)

[IAudioRenderClient::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-releasebuffer)