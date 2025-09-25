# COLORS macro

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The COLORS macro retrieves the palette entries from a [VIDEOINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfo) structure.

## Parameters

### `pbmi`

Pointer to a [VIDEOINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfo) structure.

## Remarks

This macro calculates the address as an offset from the start of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure, using the value of **bmiHeader.biSize**. Make sure to initialize the [VIDEOINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfo) structure before calling this macro.

## See also

[Video and Image Functions](https://learn.microsoft.com/windows/desktop/DirectShow/video-and-image-functions)