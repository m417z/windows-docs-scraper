# IAudioCaptureClient::ReleaseBuffer

## Description

The **ReleaseBuffer** method releases the buffer.

## Parameters

### `NumFramesRead` [in]

The number of audio frames that the client read from the capture buffer. This parameter must be either equal to the number of frames in the previously acquired data packet or 0.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_INVALID_SIZE** | The *NumFramesRead* parameter is set to a value other than the data packet size or 0. |
| **AUDCLNT_E_OUT_OF_ORDER** | This call was not preceded by a corresponding [IAudioCaptureClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer) call. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

The client should call this method when it finishes reading a data packet that it obtained previously by calling the [IAudioCaptureClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer) method.

The data in the packet that the client obtained from a [GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer) call is guaranteed to remain valid until the client calls **ReleaseBuffer** to release the packet.

Between each [GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer) call and its corresponding **ReleaseBuffer** call, the client must either read the entire data packet or none of it. If the client reads the entire packet following the **GetBuffer** call, then it should call **ReleaseBuffer** with *NumFramesRead* set to the total number of frames in the data packet. In this case, the next call to **GetBuffer** will produce a new data packet. If the client reads none of the data from the packet following the call to **GetBuffer**, then it should call **ReleaseBuffer** with *NumFramesRead* set to 0. In this case, the next **GetBuffer** call will produce the same data packet as in the previous **GetBuffer** call.

If the client calls **ReleaseBuffer** with *NumFramesRead* set to any value other than the packet size or 0, then the call fails and returns error code AUDCLNT_E_INVALID_SIZE.

Clients should avoid excessive delays between the [GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer) call that acquires a buffer and the **ReleaseBuffer** call that releases the buffer. The implementation of the audio engine assumes that the **GetBuffer** call and the corresponding **ReleaseBuffer** call occur within the same buffer-processing period. Clients that delay releasing a buffer for more than one period risk losing sample data.

For a code example that calls the **ReleaseBuffer** method, see [Capturing a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/capturing-a-stream).

## See also

[IAudioCaptureClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiocaptureclient)

[IAudioCaptureClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer)