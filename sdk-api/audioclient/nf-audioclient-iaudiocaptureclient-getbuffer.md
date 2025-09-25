# IAudioCaptureClient::GetBuffer

## Description

Retrieves a pointer to the next available packet of data in the capture endpoint buffer.

## Parameters

### `ppData` [out]

Pointer to a pointer variable into which the method writes the starting address of the next data packet that is available for the client to read.

### `pNumFramesToRead` [out]

Pointer to a **UINT32** variable into which the method writes the frame count (the number of audio frames available in the data packet). The client should either read the entire data packet or none of it.

### `pdwFlags` [out]

Pointer to a **DWORD** variable into which the method writes the buffer-status flags. The method writes either 0 or the bitwise-OR combination of one or more of the following [_AUDCLNT_BUFFERFLAGS](https://learn.microsoft.com/windows/win32/api/audioclient/ne-audioclient-_audclnt_bufferflags) enumeration values:

AUDCLNT_BUFFERFLAGS_SILENT

AUDCLNT_BUFFERFLAGS_DATA_DISCONTINUITY

AUDCLNT_BUFFERFLAGS_TIMESTAMP_ERROR

**Note** The AUDCLNT_BUFFERFLAGS_DATA_DISCONTINUITY flag is not supported in Windows Vista.

In Windows 7 and later OS releases, this flag can be used for glitch detection. To start the capture stream, the client application must call [IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start) followed by calls to **GetBuffer** in a loop to read data packets until all of the available packets in the endpoint buffer have been read. **GetBuffer** sets the AUDCLNT_BUFFERFLAGS_DATA_DISCONTINUITY flag to indicate a glitch in the buffer pointed by *ppData*.

### `pu64DevicePosition` [out]

Pointer to a **UINT64** variable into which the method writes the device position of the first audio frame in the data packet. The device position is expressed as the number of audio frames from the start of the stream. This parameter can be **NULL** if the client does not require the device position. For more information, see Remarks.

### `pu64QPCPosition` [out]

Pointer to a **UINT64** variable into which the method writes the value of the performance counter at the time that the audio endpoint device recorded the device position of the first audio frame in the data packet. The method converts the counter value to 100-nanosecond units before writing it to **pu64QPCPosition.* This parameter can be **NULL** if the client does not require the performance counter value. For more information, see Remarks.

## Return value

Possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The call succeeded and **pNumFramesToRead* is nonzero, indicating that a packet is ready to be read. |
| **AUDCLNT_S_BUFFER_EMPTY** | The call succeeded and **pNumFramesToRead* is 0, indicating that no capture data is available to be read. |
| **AUDCLNT_E_BUFFER_ERROR** | **Windows 7 and later**: [GetBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-getbuffer) failed to retrieve a data buffer and **ppData* points to **NULL**. For more information, see Remarks. |
| **AUDCLNT_E_OUT_OF_ORDER** | A previous **IAudioCaptureClient::GetBuffer** call is still in effect. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_BUFFER_OPERATION_PENDING** | Buffer cannot be accessed because a stream reset is in progress. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |
| **E_POINTER** | Parameter ppData, pNumFramesToRead, or pdwFlags is **NULL**. |

## Remarks

This method retrieves the next data packet from the capture endpoint buffer. At a particular time, the buffer might contain zero, one, or more packets that are ready to read. Typically, a buffer-processing thread that reads data from a capture endpoint buffer reads all of the available packets each time the thread executes.

During processing of an audio capture stream, the client application alternately calls **GetBuffer** and the [IAudioCaptureClient::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-releasebuffer) method. The client can read no more than a single data packet with each **GetBuffer** call. Following each **GetBuffer** call, the client must call **ReleaseBuffer** to release the packet before the client can call **GetBuffer** again to get the next packet.

Two or more consecutive calls either to **GetBuffer** or to **ReleaseBuffer** are not permitted and will fail with error code AUDCLNT_E_OUT_OF_ORDER. To ensure the correct ordering of calls, a **GetBuffer** call and its corresponding **ReleaseBuffer** call must occur in the same thread.

During each **GetBuffer** call, the caller must either obtain the entire packet or none of it. Before reading the packet, the caller can check the packet size (available through the *pNumFramesToRead* parameter) to make sure that it has enough room to store the entire packet.

During each **ReleaseBuffer** call, the caller reports the number of audio frames that it read from the buffer. This number must be either the (nonzero) packet size or 0. If the number is 0, then the next **GetBuffer** call will present the caller with the same packet as in the previous **GetBuffer** call.

Following each **GetBuffer** call, the data in the packet remains valid until the next **ReleaseBuffer** call releases the buffer.

The client must call **ReleaseBuffer** after a **GetBuffer** call that successfully obtains a packet of any size other than 0. The client has the option of calling or not calling **ReleaseBuffer** to release a packet of size 0.

The method outputs the device position and performance counter through the *pu64DevicePosition* and *pu64QPCPosition* output parameters. These values provide a time stamp for the first audio frame in the data packet. Through the *pdwFlags* output parameter, the method indicates whether the reported device position is valid.

The device position that the method writes to **pu64DevicePosition* is the stream-relative position of the audio frame that is currently playing through the speakers (for a rendering stream) or being recorded through the microphone (for a capture stream). The position is expressed as the number of frames from the start of the stream. The size of a frame in an audio stream is specified by the **nBlockAlign** member of the **WAVEFORMATEX** (or **WAVEFORMATEXTENSIBLE**) structure that specifies the stream format. The size, in bytes, of an audio frame equals the number of channels in the stream multiplied by the sample size per channel. For example, for a stereo (2-channel) stream with 16-bit samples, the frame size is four bytes.

The performance counter value that **GetBuffer** writes to **pu64QPCPosition* is not the raw counter value obtained from the **QueryPerformanceCounter** function. If *t* is the raw counter value, and if *f* is the frequency obtained from the **QueryPerformanceFrequency** function, **GetBuffer** calculates the performance counter value as follows:

**pu64QPCPosition* = 10,000,000.*t*/*f*

The result is expressed in 100-nanosecond units. For more information about **QueryPerformanceCounter** and **QueryPerformanceFrequency**, see the Windows SDK documentation.

If no new packet is currently available, the method sets **pNumFramesToRead* = 0 and returns status code AUDCLNT_S_BUFFER_EMPTY. In this case, the method does not write to the variables that are pointed to by the *ppData*, *pu64DevicePosition*, and *pu64QPCPosition* parameters.

Clients should avoid excessive delays between the **GetBuffer** call that acquires a packet and the **ReleaseBuffer** call that releases the packet. The implementation of the audio engine assumes that the **GetBuffer** call and the corresponding **ReleaseBuffer** call occur within the same buffer-processing period. Clients that delay releasing a packet for more than one period risk losing sample data.

In Windows 7 and later, **GetBuffer** can return the **AUDCLNT_E_BUFFER_ERROR** error code for an audio client that uses the endpoint buffer in the exclusive mode. This error indicates that the data buffer was not retrieved because a data packet wasn't available (**ppData* received **NULL**).

If **GetBuffer** returns **AUDCLNT_E_BUFFER_ERROR**, the thread consuming the audio samples must wait for the next processing pass. The client might benefit from keeping a count of the failed **GetBuffer** calls. If **GetBuffer** returns this error repeatedly, the client can start a new processing loop after shutting down the current client by calling [IAudioClient::Stop](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-stop), [IAudioClient::Reset](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-reset), and releasing the audio client.

#### Examples

For a code example that calls the **GetBuffer** method, see [Capturing a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/capturing-a-stream).

## See also

[IAudioCaptureClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiocaptureclient)

[IAudioCaptureClient::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiocaptureclient-releasebuffer)

[IAudioClient::GetMixFormat](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getmixformat)

[IAudioClock::GetPosition](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclock-getposition)