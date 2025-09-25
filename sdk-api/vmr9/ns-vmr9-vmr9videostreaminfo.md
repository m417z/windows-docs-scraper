# VMR9VideoStreamInfo structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMR9VideoStreamInfo` structure describes the rendering parameters for a video compositing operation in the VRM-9 filter. This structure is used in the [IVMRImageCompositor9::CompositeImage](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrimagecompositor9-compositeimage) method.

## Members

### `pddsVideoSurface`

A pointer to the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface of the Direct3D surface that contains the video to be composited.

### `dwWidth`

The width of the video rectangle.

### `dwHeight`

The height of the video rectangle.

### `dwStrmID`

Specifies the input stream. This value corresponds to the input pin.

### `fAlpha`

The alpha value for this stream. (Not per-pixel alpha.)

### `rNormal`

The position of the image in composition space, as a [VMR9NormalizedRect](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9normalizedrect) structure.

### `rtStart`

The start time of the video frame, in 100-nanosecond units.

### `rtEnd`

The end time of the video frame, in 100-nanosecond units.

### `SampleFormat`

The video interlacing format, specified as a member of the [VMR9_SampleFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9_sampleformat) enumeration type.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)