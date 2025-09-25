# PALETTISED macro

## Syntax

```cpp
BOOL PALETTISED(
    VIDEOINFOHEADER *pbmi
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the color depth (**bmiHeader.biBitCount**) is 8 bits or less, or **FALSE** otherwise.

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PALETTISED` macro checks whether a bitmap has a color depth of 8 bits or less.

## Parameters

### `pbmi`

Pointer to a [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure.

## See also

[ContainsPalette](https://learn.microsoft.com/windows/desktop/DirectShow/containspalette)

[PALETTE_ENTRIES](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-palette_entries)

[Video and Image Functions](https://learn.microsoft.com/windows/desktop/DirectShow/video-and-image-functions)