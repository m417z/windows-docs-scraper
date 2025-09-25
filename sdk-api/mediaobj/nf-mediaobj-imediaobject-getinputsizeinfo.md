# IMediaObject::GetInputSizeInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetInputSizeInfo` method retrieves the buffer requirements for a specified input stream.

## Parameters

### `dwInputStreamIndex`

Zero-based index of an input stream on the DMO.

### `pcbSize` [out]

Pointer to a variable that receives the minimum size of an input buffer for this stream, in bytes.

### `pcbMaxLookahead` [out]

Pointer to a variable that receives the maximum amount of data that the DMO will hold for lookahead, in bytes. If the DMO does not perform lookahead on the stream, the value is zero.

### `pcbAlignment` [out]

Pointer to a variable that receives the required buffer alignment, in bytes. If the input stream has no alignment requirement, the value is 1.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index. |
| **DMO_E_TYPE_NOT_SET** | Media type was not set. |
| **S_OK** | Success. |

## Remarks

The buffer requirements may depend on the media types of the various streams. Before calling this method, set the media type of each stream by calling the [IMediaObject::SetInputType](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-setinputtype) and [IMediaObject::SetOutputType](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-setoutputtype) methods. If the media types have not been set, this method might return an error.

If the DMO performs lookahead on the input stream, it returns the DMO_INPUT_STREAMF_HOLDS_BUFFERS flag in the [IMediaObject::GetInputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-getinputstreaminfo) method. During processing, the DMO holds up to the number of bytes indicated by the *pcbMaxLookahead* parameter. The application must allocate enough buffers for the DMO to hold this much data.

A buffer is *aligned* if the buffer's start address is a multiple of **pcbAlignment*. The alignment must be a power of two. Depending on the microprocessor, reads and writes to an aligned buffer might be faster than to an unaligned buffer. Also, some microprocessors do not support unaligned reads and writes.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)