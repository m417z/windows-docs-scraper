# GetBitmapSize function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetBitmapSize` function calculates the number of bytes required by a device-independent bitmap (DIB). This function simply calls the [**DIBSIZE**](https://learn.microsoft.com/previous-versions/windows/desktop/api/Amvideo/nf-amvideo-dibsize) macro.

## Parameters

*pHeader*

Pointer to a [**BITMAPINFOHEADER**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

## Return value

Returns the size in bytes.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxutil.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [Video and Image Functions](https://learn.microsoft.com/windows/win32/directshow/video-and-image-functions)