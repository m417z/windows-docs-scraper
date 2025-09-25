# COLORKEY structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `COLORKEY` structure communicates color key information between the renderer and another filter.

## Members

### `KeyType`

Key type. Can be **CK_NOCOLORKEY**, **CK_INDEX**, or **CK_RGB**. The **CK_INDEX** and **CK_RGB** can be combined with a bitwise **OR**.

### `PaletteIndex`

Palette index.

### `LowColorValue`

Lowest RGB color value.

### `HighColorValue`

Highest RGB color value.

## Remarks

The video renderer supports a data transport accessed through the [IOverlay](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlay) interface. This will typically be used by hardware decoder filters that need the renderer to communicate where to put the data rather than requiring the renderer to draw the data. One mechanism for communicating where to put the images is by using a color key. This structure is used by a filter (typically a hardware decoder) to describe color key requirements to the video renderer.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)