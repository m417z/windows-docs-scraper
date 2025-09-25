# HEADER macro

## Syntax

```cpp
BITMAPINFOHEADER HEADER(
    VIDEOINFOHEADER *pVideoInfo
);
```

## Return value

Type: **BITMAPINFOHEADER**

Returns the address of the [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure's **bmiHeader** member.

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **HEADER** macro returns the address of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) within a [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader).

## Parameters

### `pVideoInfo`

Pointer to a [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure.

## See also

[Video and Image Functions](https://learn.microsoft.com/windows/desktop/DirectShow/video-and-image-functions)