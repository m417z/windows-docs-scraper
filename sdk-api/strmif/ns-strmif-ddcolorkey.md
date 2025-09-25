# DDCOLORKEY structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Describes a color key as a range of values.

## Members

### `dw1`

Specifies the lower bound of the color key range.

### `dw2`

Specifies the upper bound of the color key range.

## Remarks

This structure is used by the Video Mixing Renderer (VMR) filter. The VMR uses this structure to support the DirectDraw capability of specifying a range of values for a color key by using two **DWORD**s. The VMR and the graphics card automatically determine whether the two **DWORD**s are interpreted as RGB or YUV color space values. Not all hardware may support this capability. To ensure compatibility with all hardware, set **dw1** and **dw2** to the same value.