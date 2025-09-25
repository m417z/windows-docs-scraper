# IMediaObject::ProcessOutput

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ProcessOutput` method generates output from the current input data.

## Parameters

### `dwFlags`

Bitwise combination of zero or more flags from the [DMO_PROCESS_OUTPUT_FLAGS](https://learn.microsoft.com/windows/desktop/api/mediaobj/ne-mediaobj-_dmo_process_output_flags) enumeration.

### `cOutputBufferCount`

Number of output buffers.

### `pOutputBuffers` [in, out]

Pointer to an array of [DMO_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/previous-versions/windows/desktop/api/mediaobj/ns-mediaobj-dmo_output_data_buffer) structures containing the output buffers. Specify the size of the array in the *cOutputBufferCount* parameter.

### `pdwStatus` [out]

Pointer to a variable that receives a reserved value (zero). The application should ignore this value.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure |
| **E_INVALIDARG** | Invalid argument |
| **E_POINTER** | **NULL** pointer argument |
| **S_FALSE** | No output was generated |
| **S_OK** | Success |

## Remarks

The *pOutputBuffers* parameter points to an array of **DMO_OUTPUT_DATA_BUFFER** structures. The application must allocate one structure for each output stream. To determine the number of output streams, call the [IMediaObject::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-getstreamcount) method. Set the *cOutputBufferCount* parameter to this number.

Each **DMO_OUTPUT_DATA_BUFFER** structure contains a pointer to a buffer's [IMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediabuffer) interface. The application allocates these buffers. The other members of the structure are status fields. The DMO sets these fields if the method succeeds. If the method fails, their values are undefined.

When the application calls `ProcessOutput`, the DMO processes as much input data as possible. It writes the output data to the output buffers, starting from the end of the data in each buffer. (To find the end of the data, call the [IMediaBuffer::GetBufferAndLength](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediabuffer-getbufferandlength) method.) The DMO never holds a reference count on an output buffer.

If the DMO fills an entire output buffer and still has input data to process, the DMO returns the DMO_OUTPUT_DATA_BUFFERF_INCOMPLETE flag in the **DMO_OUTPUT_DATA_BUFFER** structure. The application should check for this flag by testing the **dwStatus** member of each structure.

If the method returns S_FALSE, no output was generated. However, a DMO is not required to return S_FALSE in this situation; it might return S_OK.

**Discarding data:**

You can discard data from a stream by setting the DMO_PROCESS_OUTPUT_DISCARD_WHEN_NO_BUFFER flag in the *dwFlags* parameter. For each stream that you want to discard, set the **pBuffer** member of the **DMO_OUTPUT_DATA_BUFFER** structure to **NULL**.

For each stream in which **pBuffer** is **NULL**:

* If the DMO_PROCESS_OUTPUT_DISCARD_WHEN_NO_BUFFER flag is set, and the stream is discardable or optional, the DMO discards the data.
* If the flag is set but the stream is neither discardable nor optional, the DMO discards the data if possible. It is not guaranteed to discard the data.
* If the flag is not set, the DMO does not produce output data for that stream, but does not discard the data.

To check whether a stream is discardable or optional, call the [IMediaObject::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-getoutputstreaminfo) method.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)