# IMediaSample::GetMediaType

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetMediaType` method retrieves the media type, if the media type differs from the previous sample.

## Parameters

### `ppMediaType`

Address of a variable that receives a pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure. If the media type has not changed from the previous sample, **ppMediaType* is set to **NULL**.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The media type has not changed from the previous sample. |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

This method enables a filter to make limited changes to the media type, such as changing the palette. To make a significant change to the media type, the pins might need to reconnect and renegotiate the media type.

If the method returns S_OK, the caller must free the memory for the media type, including the format block. You can use the [DeleteMediaType](https://learn.microsoft.com/windows/desktop/DirectShow/deletemediatype) function in the DirectShow base class library.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSample Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample)