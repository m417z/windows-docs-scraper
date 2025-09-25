# IAudioRenderClient::GetBuffer

## Description

Retrieves a pointer to the next available space in the rendering endpoint buffer into which the caller can write a data packet.

## Parameters

### `NumFramesRequested` [in]

The number of audio frames in the data packet that the caller plans to write to the requested space in the buffer. If the call succeeds, the size of the buffer area pointed to by **ppData* matches the size specified in *NumFramesRequested*.

### `ppData` [out]

Pointer to a pointer variable into which the method writes the starting address of the buffer area into which the caller will write the data packet.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_BUFFER_ERROR** | [GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) failed to retrieve a data buffer and **ppData* points to **NULL**. For more information, see Remarks. |
| **AUDCLNT_E_BUFFER_TOO_LARGE** | The *NumFramesRequested* value exceeds the available buffer space (buffer size minus padding size). |
| **AUDCLNT_E_BUFFER_SIZE_ERROR** | The stream is exclusive mode and uses event-driven buffering, but the client attempted to get a packet that was not the size of the buffer. |
| **AUDCLNT_E_OUT_OF_ORDER** | A previous **IAudioRenderClient::GetBuffer** call is still in effect. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_BUFFER_OPERATION_PENDING** | Buffer cannot be accessed because a stream reset is in progress. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |
| **E_POINTER** | Parameter *ppData* is **NULL**. |

## Remarks

The caller can request a packet size that is less than or equal to the amount of available space in the buffer (except in the case of an exclusive-mode stream that uses event-driven buffering; for more information, see [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)). The available space is simply the buffer size minus the amount of data in the buffer that is already queued up to be played. If the caller specifies a *NumFramesRequested* value that exceeds the available space in the buffer, the call fails and returns error code AUDCLNT_E_BUFFER_TOO_LARGE.

The client is responsible for writing a sufficient amount of data to the buffer to prevent glitches from occurring in the audio stream. For more information about buffering requirements, see [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize).

After obtaining a data packet by calling **GetBuffer**, the client fills the packet with rendering data and issues the packet to the audio engine by calling the [IAudioRenderClient::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-releasebuffer) method.

The client must call **ReleaseBuffer** after a **GetBuffer** call that successfully obtains a packet of any size other than 0. The client has the option of calling or not calling **ReleaseBuffer** to release a packet of size 0.

For nonzero packet sizes, the client must alternate calls to **GetBuffer** and **ReleaseBuffer**. Each **GetBuffer** call must be followed by a corresponding **ReleaseBuffer** call. After the client has called **GetBuffer** to acquire a data packet, the client cannot acquire the next data packet until it has called **ReleaseBuffer** to release the previous packet. Two or more consecutive calls either to **GetBuffer** or to **ReleaseBuffer** are not permitted and will fail with error code AUDCLNT_E_OUT_OF_ORDER.

To ensure the correct ordering of calls, a **GetBuffer** call and its corresponding **ReleaseBuffer** call must occur in the same thread.

The size of an audio frame is specified by the **nBlockAlign** member of the **WAVEFORMATEX** structure that the client obtains by calling the [IAudioClient::GetMixFormat](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getmixformat) method.

If the caller sets *NumFramesRequested* = 0, the method returns status code S_OK but does not write to the variable that the *ppData* parameter points to.

Clients should avoid excessive delays between the **GetBuffer** call that acquires a buffer and the **ReleaseBuffer** call that releases the buffer. The implementation of the audio engine assumes that the **GetBuffer** call and the corresponding **ReleaseBuffer** call occur within the same buffer-processing period. Clients that delay releasing a buffer for more than one period risk losing sample data.

In Windows 7, **GetBuffer** can return the **AUDCLNT_E_BUFFER_ERROR** error code for an audio client that uses the endpoint buffer in the exclusive mode. This error indicates that the data buffer was not retrieved because a data packet was not available (**ppData* received **NULL**).

If **GetBuffer** returns **AUDCLNT_E_BUFFER_ERROR**, the thread consuming the audio samples must wait for the next processing pass. The client might benefit from keeping a count of the failed **GetBuffer** calls. If **GetBuffer** returns this error repeatedly, the client can start a new processing loop after shutting down the current client by calling [IAudioClient::Stop](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-stop), [IAudioClient::Reset](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-reset), and releasing the audio client.

#### Examples

For code examples that call the **GetBuffer** method, see the following topics:

* [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream)
* [Exclusive-Mode Streams](https://learn.microsoft.com/windows/desktop/CoreAudio/exclusive-mode-streams)

## See also

[IAudioClient::GetBufferSize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getbuffersize)

[IAudioClient::GetCurrentPadding](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getcurrentpadding)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioRenderClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiorenderclient)

[IAudioRenderClient::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-releasebuffer)