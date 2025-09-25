# IAudioRenderClient::ReleaseBuffer

## Description

The **ReleaseBuffer** method releases the buffer space acquired in the previous call to the [IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) method.

## Parameters

### `NumFramesWritten` [in]

The number of audio frames written by the client to the data packet. The value of this parameter must be less than or equal to the size of the data packet, as specified in the *NumFramesRequested* parameter passed to the [IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) method.

### `dwFlags` [in]

The buffer-configuration flags. The caller can set this parameter either to 0 or to the following [_AUDCLNT_BUFFERFLAGS](https://learn.microsoft.com/windows/win32/api/audioclient/ne-audioclient-_audclnt_bufferflags) enumeration value (a flag bit):

AUDCLNT_BUFFERFLAGS_SILENT

If this flag bit is set, the audio engine treats the data packet as though it contains silence regardless of the data values contained in the packet. This flag eliminates the need for the client to explicitly write silence data to the rendering buffer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_INVALID_SIZE** | The *NumFramesWritten* value exceeds the *NumFramesRequested* value specified in the previous [IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) call. |
| **AUDCLNT_E_BUFFER_SIZE_ERROR** | The stream is exclusive mode and uses event-driven buffering, but the client attempted to release a packet that was not the size of the buffer. |
| **AUDCLNT_E_OUT_OF_ORDER** | This call was not preceded by a corresponding call to [IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer). |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |
| **E_INVALIDARG** | Parameter *dwFlags* is not a valid value.\ |

## Remarks

The client must release the same number of frames that it requested in the preceding call to the [IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) method. The single exception to this rule is that the client can always call **ReleaseBuffer** to release 0 frames (unless the stream is exclusive mode and uses event-driven buffering).

This behavior provides a convenient means for the client to "release" a previously requested packet of length 0. In this case, the call to **ReleaseBuffer** is optional. After calling [GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) to obtain a packet of length 0, the client has the option of not calling **ReleaseBuffer** before calling **GetBuffer** again.

In addition, if the preceding [GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) call obtained a packet of nonzero size, calling **ReleaseBuffer** with *NumFramesRequested* set to 0 will succeed (unless the stream is exclusive mode and uses event-driven buffering). The meaning of the call is that the client wrote no data to the packet before releasing it. Thus, the method treats the portion of the buffer represented by the packet as unused and will make this portion of the buffer available again to the client in the next **GetBuffer** call.

Clients should avoid excessive delays between the [GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer) call that acquires a buffer and the **ReleaseBuffer** call that releases the buffer. The implementation of the audio engine assumes that the **GetBuffer** call and the corresponding **ReleaseBuffer** call occur within the same buffer-processing period. Clients that delay releasing a buffer for more than one period risk losing sample data.

For code examples that call the **ReleaseBuffer** method, see the following topics:

* [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream)
* [Exclusive-Mode Streams](https://learn.microsoft.com/windows/desktop/CoreAudio/exclusive-mode-streams)

## See also

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioRenderClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiorenderclient)

[IAudioRenderClient::GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiorenderclient-getbuffer)