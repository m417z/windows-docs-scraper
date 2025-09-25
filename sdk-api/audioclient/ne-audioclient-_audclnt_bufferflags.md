# _AUDCLNT_BUFFERFLAGS enumeration

## Description

The **_AUDCLNT_BUFFERFLAGS** enumeration defines flags that indicate the status of an audio endpoint buffer.

## Constants

### `AUDCLNT_BUFFERFLAGS_DATA_DISCONTINUITY`

The data in the packet is not correlated with the previous packet's device position; this is possibly due to a stream state transition or timing glitch.

### `AUDCLNT_BUFFERFLAGS_SILENT`

Treat all of the data in the packet as silence and ignore the actual data values. For more information about the use of this flag, see [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream) and [Capturing a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/capturing-a-stream).

### `AUDCLNT_BUFFERFLAGS_TIMESTAMP_ERROR`

The time at which the device's stream position was recorded is uncertain. Thus, the client might be unable to accurately set the time stamp for the current data packet.

## Remarks

The [IAudioCaptureClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer) and [IAudioRenderClient::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-releasebuffer) methods use the constants defined in the **_AUDCLNT_BUFFERFLAGS** enumeration.

## See also

[Core Audio Enumerations](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-enumerations)

[IAudioCaptureClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer)

[IAudioRenderClient::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-releasebuffer)