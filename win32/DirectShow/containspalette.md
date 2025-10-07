# ContainsPalette function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **ContainsPalette** function determines whether a specified [**VIDEOINFOHEADER**](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure contains a palette.

## Parameters

*pVideoInfo*

Pointer to a [**VIDEOINFOHEADER**](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure.

## Return value

Returns **TRUE** if the bitdepth is 8 or less (**bmiHeader.biBitCount**), or the number of color indexes is more than zero (**bmiHeader.biClrUsed**). Returns **FALSE** otherwise.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxutil.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [Video and Image Functions](https://learn.microsoft.com/windows/win32/directshow/video-and-image-functions)