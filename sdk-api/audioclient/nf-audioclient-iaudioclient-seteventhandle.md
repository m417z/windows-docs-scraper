# IAudioClient::SetEventHandle

## Description

The **SetEventHandle** method sets the event handle that the system signals when an audio buffer is ready to be processed by the client.

## Parameters

### `eventHandle` [in]

The event handle.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *eventHandle* is **NULL** or an invalid handle. |
| **AUDCLNT_E_EVENTHANDLE_NOT_EXPECTED** | The audio stream was not initialized for event-driven buffering. |
| **AUDCLNT_E_NOT_INITIALIZED** | The audio stream has not been successfully initialized. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method requires prior initialization of the [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) interface. All calls to this method will fail with the error AUDCLNT_E_NOT_INITIALIZED until the client initializes the audio stream by successfully calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method.

During stream initialization, the client can, as an option, enable event-driven buffering. To do so, the client calls the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method with the AUDCLNT_STREAMFLAGS_EVENTCALLBACK flag set. After enabling event-driven buffering, and before calling the [IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start) method to start the stream, the client must call **SetEventHandle** to register the event handle that the system will signal each time a buffer becomes ready to be processed by the client.

The event handle should be in the nonsignaled state at the time that the client calls the [Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start) method.

If the client has enabled event-driven buffering of a stream, but the client calls the [Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start) method for that stream without first calling **SetEventHandle**, the **Start** call will fail and return an error code.

If the client does not enable event-driven buffering of a stream but attempts to set an event handle for the stream by calling **SetEventHandle**, the call will fail and return an error code.

For a code example that calls the **SetEventHandle** method, see [Exclusive-Mode Streams](https://learn.microsoft.com/windows/desktop/CoreAudio/exclusive-mode-streams).

## See also

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start)