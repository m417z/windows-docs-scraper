# IAudioClient::Reset

## Description

The **Reset** method resets the audio stream.

## Return value

If the method succeeds, it returns S_OK. If the method succeeds and the stream was already reset, the method returns S_FALSE. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_NOT_INITIALIZED** | The audio stream has not been successfully initialized. |
| **AUDCLNT_E_NOT_STOPPED** | The audio stream was not stopped at the time the call was made. |
| **AUDCLNT_E_BUFFER_OPERATION_PENDING** | The client is currently writing to or reading from the buffer. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method requires prior initialization of the [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) interface. All calls to this method will fail with the error AUDCLNT_E_NOT_INITIALIZED until the client initializes the audio stream by successfully calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method.

**Reset** is a control method that the client calls to reset a stopped audio stream. Resetting the stream flushes all pending data and resets the audio clock stream position to 0. This method fails if it is called on a stream that is not stopped.

## See also

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)