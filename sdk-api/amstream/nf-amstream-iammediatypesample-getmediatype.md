# IAMMediaTypeSample::GetMediaType

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

> [!NOTE]
> This interface is deprecated. New applications should not use it.

The `GetMediaType` method retrieves the media type of the sample. If the format has not changed from the previous sample, the sample might not carry a media type.

## Parameters

### `ppMediaType`

Address of a pointer that receives an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **S_FALSE** | The format has not changed from the previous sample. |
| **S_OK** | Success. |

## See also

[IAMMediaTypeSample Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammediatypesample)