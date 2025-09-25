# NORMALIZEDRECT structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `NORMALIZEDRECT` structure is used with the VMR filter in mixing operations to specify the location of a video rectangle in composition space.

## Members

### `left`

The left corner of the normalized rectangle.

### `top`

The top corner of the normalized rectangle.

### `right`

The right corner of the normalized rectangle.

### `bottom`

The bottom corner of the normalized rectangle.

## Remarks

This structure is used in methods involving "composition space," which refers to the visible video rectangle, as well as the offscreen space necessary to contain rectangles from secondary streams. See [Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer) for more information.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)