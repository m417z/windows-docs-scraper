# IAudioCaptureClient::GetNextPacketSize

## Description

The **GetNextPacketSize** method retrieves the number of frames in the next data packet in the capture endpoint buffer.

## Parameters

### `pNumFramesInNextPacket` [out]

Pointer to a **UINT32** variable into which the method writes the frame count (the number of audio frames in the next capture packet).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |
| **E_POINTER** | Parameter *pNumFramesInNextPacket* is **NULL**. |

## Remarks

Use this method only with shared-mode streams. It does not work with exclusive-mode streams.

Before calling the [IAudioCaptureClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer) method to retrieve the next data packet, the client can call **GetNextPacketSize** to retrieve the number of audio frames in the next packet. The count reported by **GetNextPacketSize** matches the count retrieved in the **GetBuffer** call (through the *pNumFramesToRead* output parameter) that follows the **GetNextPacketSize** call.

A packet always consists of an integral number of audio frames.

**GetNextPacketSize** must be called in the same thread as the [GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer) and [IAudioCaptureClient::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-releasebuffer) method calls that get and release the packets in the capture endpoint buffer.

For a code example that uses the **GetNextPacketSize** method, see [Capturing a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/capturing-a-stream).

## See also

[IAudioCaptureClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiocaptureclient)

[IAudioCaptureClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer)

[IAudioCaptureClient::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-releasebuffer)

[IAudioClient::GetCurrentPadding](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getcurrentpadding)