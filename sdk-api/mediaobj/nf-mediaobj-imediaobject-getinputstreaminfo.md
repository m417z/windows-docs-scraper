# IMediaObject::GetInputStreamInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetInputStreamInfo` method retrieves information about an input stream, such as any restrictions on the number of samples per buffer, and whether the stream performs lookahead on the input data. This information never changes.

## Parameters

### `dwInputStreamIndex`

Zero-based index of an input stream on the DMO.

### `pdwFlags` [out]

Pointer to a variable that receives a bitwise combination of zero or more [DMO_INPUT_STREAM_INFO_FLAGS](https://learn.microsoft.com/windows/desktop/api/mediaobj/ne-mediaobj-_dmo_input_stream_info_flags) flags.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index |
| **E_POINTER** | **NULL** pointer argument |
| **S_OK** | Success |

## Remarks

The DMO_INPUT_STREAMF_HOLDS_BUFFERS flag indicates that the DMO performs lookahead on the incoming data.

The application must be sure to allocate sufficient buffers for the DMO to process the input. Call the [IMediaObject::GetInputSizeInfo](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-getinputsizeinfo) method to determine the buffer requirements.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)