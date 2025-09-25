# IAudioClient::Stop

## Description

The **Stop** method stops the audio stream.

## Return value

If the method succeeds and stops the stream, it returns S_OK. If the method succeeds and the stream was already stopped, the method returns S_FALSE. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_NOT_INITIALIZED** | The client has not been successfully initialized. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method requires prior initialization of the [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) interface. All calls to this method will fail with the error AUDCLNT_E_NOT_INITIALIZED until the client initializes the audio stream by successfully calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method.

**Stop** is a control method that stops a running audio stream. This method stops data from streaming through the client's connection with the audio engine. Stopping the stream freezes the stream's audio clock at its current stream position. A subsequent call to [IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start) causes the stream to resume running from that position. If necessary, the client can call the [IAudioClient::Reset](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-reset) method to reset the position while the stream is stopped.

For code examples that call the **Stop** method, see the following topics:

* [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream)
* [Capturing a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/capturing-a-stream)

## See also

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioClient::Reset](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-reset)

[IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start)