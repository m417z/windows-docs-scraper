# IAudioClient::GetCurrentPadding

## Description

The **GetCurrentPadding** method retrieves the number of frames of padding in the endpoint buffer.

## Parameters

### `pNumPaddingFrames` [out]

Pointer to a **UINT32** variable into which the method writes the frame count (the number of audio frames of padding in the buffer).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_NOT_INITIALIZED** | The audio stream has not been successfully initialized. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |
| **E_POINTER** | Parameter *pNumPaddingFrames* is **NULL**. |

## Remarks

This method requires prior initialization of the [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) interface. All calls to this method will fail with the error AUDCLNT_E_NOT_INITIALIZED until the client initializes the audio stream by successfully calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method.

This method retrieves a padding value that indicates the amount of valid, unread data that the endpoint buffer currently contains. A rendering application can use the padding value to determine how much new data it can safely write to the endpoint buffer without overwriting previously written data that the audio engine has not yet read from the buffer. A capture application can use the padding value to determine how much new data it can safely read from the endpoint buffer without reading invalid data from a region of the buffer to which the audio engine has not yet written valid data.

The padding value is expressed as a number of audio frames. The size of an audio frame is specified by the **nBlockAlign** member of the [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) (or [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-waveformatextensible)) structure that the client passed to the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method. The size in bytes of an audio frame equals the number of channels in the stream multiplied by the sample size per channel. For example, the frame size is four bytes for a stereo (2-channel) stream with 16-bit samples.

For a shared-mode rendering stream, the padding value reported by **GetCurrentPadding** specifies the number of audio frames that are queued up to play in the endpoint buffer. Before writing to the endpoint buffer, the client can calculate the amount of available space in the buffer by subtracting the padding value from the buffer length. To ensure that a subsequent call to the [IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) method succeeds, the client should request a packet length that does not exceed the available space in the buffer. To obtain the buffer length, call the [IAudioClient::GetBufferSize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getbuffersize) method.

For a shared-mode capture stream, the padding value reported by **GetCurrentPadding** specifies the number of frames of capture data that are available in the next packet in the endpoint buffer. At a particular moment, zero, one, or more packets of capture data might be ready for the client to read from the buffer. If no packets are currently available, the method reports a padding value of 0. Following the **GetCurrentPadding** call, an [IAudioCaptureClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer) method call will retrieve a packet whose length exactly equals the padding value reported by **GetCurrentPadding**. Each call to [GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) retrieves a whole packet. A packet always contains an integral number of audio frames.

For a shared-mode capture stream, calling **GetCurrentPadding** is equivalent to calling the [IAudioCaptureClient::GetNextPacketSize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getnextpacketsize) method. That is, the padding value reported by **GetCurrentPadding** is equal to the packet length reported by **GetNextPacketSize**.

For an exclusive-mode rendering or capture stream that was initialized with the AUDCLNT_STREAMFLAGS_EVENTCALLBACK flag, the client typically has no use for the padding value reported by **GetCurrentPadding**. Instead, the client accesses an entire buffer during each processing pass. Each time a buffer becomes available for processing, the audio engine notifies the client by signaling the client's event handle. For more information about this flag, see [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize).

For an exclusive-mode rendering or capture stream that was not initialized with the AUDCLNT_STREAMFLAGS_EVENTCALLBACK flag, the client can use the padding value obtained from **GetCurrentPadding** in a way that is similar to that described previously for a shared-mode stream. The details are as follows.

First, for an exclusive-mode rendering stream, the padding value specifies the number of audio frames that are queued up to play in the endpoint buffer. As before, the client can calculate the amount of available space in the buffer by subtracting the padding value from the buffer length.

Second, for an exclusive-mode capture stream, the padding value reported by **GetCurrentPadding** specifies the current length of the next packet. However, this padding value is a snapshot of the packet length, which might increase before the client calls the [IAudioCaptureClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer) method. Thus, the length of the packet retrieved by **GetBuffer** is at least as large as, but might be larger than, the padding value reported by the **GetCurrentPadding** call that preceded the **GetBuffer** call. In contrast, for a shared-mode capture stream, the length of the packet obtained from **GetBuffer** always equals the padding value reported by the preceding **GetCurrentPadding** call.

For a code example that calls the **GetCurrentPadding** method, see [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream).

## See also

[IAudioCaptureClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer)

[IAudioCaptureClient::GetNextPacketSize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getnextpacketsize)

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer)