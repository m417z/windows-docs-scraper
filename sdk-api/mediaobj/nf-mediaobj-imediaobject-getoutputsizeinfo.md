# IMediaObject::GetOutputSizeInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetOutputSizeInfo` method retrieves the buffer requirements for a specified output stream.

## Parameters

### `dwOutputStreamIndex`

Zero-based index of an output stream on the DMO.

### `pcbSize` [out]

Pointer to a variable that receives the minimum size of an output buffer for this stream, in bytes.

### `pcbAlignment` [out]

Pointer to a variable that receives the required buffer alignment, in bytes. If the output stream has no alignment requirement, the value is 1.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index. |
| **DMO_E_TYPE_NOT_SET** | Media type was not set. |
| **S_OK** | Success. |

## Remarks

The buffer requirements may depend on the media types set for each of the streams.

Before calling this method, set the media type of each stream by calling the [IMediaObject::SetInputType](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-setinputtype) and [IMediaObject::SetOutputType](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-setoutputtype) methods. If the media types have not been set, this method might return an error. However, if a stream is optional, and the application will not use the stream, you do not have to set the media type for the stream.

A buffer is *aligned* if the buffer's start address is a multiple of **pcbAlignment*. Depending on the architecture of the microprocessor, it is faster to read and write to an aligned buffer than to an unaligned buffer. On some microprocessors, reading and writing to an unaligned buffer is not supported and can cause the program to crash. Zero is not a valid alignment.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)