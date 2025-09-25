# IMediaObject::ProcessInput

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ProcessInput` method delivers a buffer to the specified input stream.

## Parameters

### `dwInputStreamIndex`

Zero-based index of an input stream on the DMO.

### `pBuffer`

Pointer to the buffer's [IMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediabuffer) interface.

### `dwFlags`

Bitwise combination of zero or more flags from the [DMO_INPUT_DATA_BUFFER_FLAGS](https://learn.microsoft.com/windows/desktop/api/mediaobj/ne-mediaobj-_dmo_input_data_buffer_flags) enumeration.

### `rtTimestamp`

Time stamp that specifies the start time of the data in the buffer. If the buffer has a valid time stamp, set the DMO_INPUT_DATA_BUFFERF_TIME flag in the *dwFlags* parameter. Otherwise, the DMO ignores this value.

### `rtTimelength`

Reference time specifying the duration of the data in the buffer. If this value is valid, set the DMO_INPUT_DATA_BUFFERF_TIMELENGTH flag in the *dwFlags* parameter. Otherwise, the DMO ignores this value.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index. |
| **DMO_E_NOTACCEPTING** | Data cannot be accepted. |
| **S_FALSE** | No output to process. |
| **S_OK** | Success. |

## Remarks

The input buffer specified in the *pBuffer* parameter is read-only. The DMO will not modify the data in this buffer. All write operations occur on the output buffers, which are given in a separate call to the [IMediaObject::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processoutput) method.

If the DMO does not process all the data in the buffer, it keeps a reference count on the buffer. It releases the buffer once it has generated all the output, unless it needs to perform lookahead on the data. (To determine whether a DMO performs lookahead, call the [IMediaObject::GetInputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-getinputstreaminfo) method.)

If this method returns DMO_E_NOTACCEPTING, call **ProcessOutput** until the input stream can accept more data. To determine whether the stream can accept more data, call the [IMediaObject::GetInputStatus](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-getinputstatus) method.

If the method returns S_FALSE, no output was generated from this input and the application does not need to call **ProcessOutput**. However, a DMO is not required to return S_FALSE in this situation; it might return S_OK.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)