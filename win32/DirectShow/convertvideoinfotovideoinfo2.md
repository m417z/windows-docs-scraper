# ConvertVideoInfoToVideoInfo2 function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ConvertVideoInfoToVideoInfo2` function converts a media type that uses [**VIDEOINFOHEADER**](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) to one that uses [**VIDEOINFOHEADER2**](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2).

## Parameters

*pmt*

Pointer to the [**AM\_MEDIA\_TYPE**](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_media_type) structure to convert. The structure must have format type FORMAT\_VideoInfo.

## Return value

Returns S\_OK or E\_OUTOFMEMORY.

## Remarks

This function allocates a new **VIDEOINFOHEADER2** structure, copies the members of the **VIDEOINFOHEADER** structure into it, and replaces the old structure with the new structure in the format block of the media type.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Winutil.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [Video and Image Functions](https://learn.microsoft.com/windows/win32/directshow/video-and-image-functions)