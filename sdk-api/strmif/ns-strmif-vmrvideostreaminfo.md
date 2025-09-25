# VMRVIDEOSTREAMINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

This topic applies to Windows XP or later.

The `VMRVIDEOSTREAMINFO` structure is used in the VMR-7 filter's call to [IVMRImageCompositor::CompositeImage](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrimagecompositor-compositeimage) on the image compositor.

## Members

### `pddsVideoSurface`

Specifies the DirectDraw surface that contains the video to be composited.

### `dwWidth`

Specifies the width of the video rectangle.

### `dwHeight`

Specifies the height of the video rectangle.

### `dwStrmID`

Specifies the input stream. This value corresponds to the input pin.

### `fAlpha`

Specifies the alpha value for this stream. (Not per-pixel alpha.)

### `ddClrKey`

Specifies the source color key value or -1 if color keying is not to be used for this stream.

### `rNormal`

Specifies the position of the image in composition space.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)