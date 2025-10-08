# CreateMediaType function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CreateMediaType** function allocates a new [**AM\_MEDIA\_TYPE**](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_media_type) structure, including the format block.

## Parameters

*pSrc*

Pointer to an [**AM\_MEDIA\_TYPE**](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_media_type) structure. The method copies this structure into the new structure.

## Return value

Returns a new [**AM\_MEDIA\_TYPE**](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_media_type) structure, or **NULL** if there is an error.

## Remarks

To free the memory allocated by this function, call [**DeleteMediaType**](https://learn.microsoft.com/windows/win32/directshow/deletemediatype).

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Mtype.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds); <br>Strmbasd.lib (debug builds) |

## See also

[**Media Type Functions**](https://learn.microsoft.com/windows/win32/directshow/media-type-functions)

