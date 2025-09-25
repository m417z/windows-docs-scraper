# AMVAUncompBufferInfo structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AMVAUncompBufferInfo** structure describes the uncompressed surfaces to be allocated by the video renderer.

## Members

### `dwMinNumSurfaces`

Minimum number of surfaces to allocate.

### `dwMaxNumSurfaces`

Maximum number of surfaces to allocate.

### `ddUncompPixelFormat`

**DDPIXELFORMAT** structure, describing the pixel format of the allocated surfaces.

## Remarks

The VMR-7 and VMR-9 filters allocate at least **dwMinNumSurfaces** surfaces. For interlaced content, the VMR-7 allocates additional surfaces equal to the number of forward and backward reference frames required by the deinterlacer. The VMR-7 gets these values by calling [IVMRDeinterlaceControl::GetDeinterlaceModeCaps](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrdeinterlacecontrol-getdeinterlacemodecaps). The VMR-9 does not need to allocate additional surfaces for deinterlacing. Thus:

* For the VMR-7, the number of allocated surfaces is **dwMinNumSurfaces** + **dwNumForwardRefSamples** + **dwNumBackwardRefSamples**. For progressive content, the last two values will be zero.
* For the VMR-9, the number of allocated surfaces is **dwMinNumSurfaces**.

Initially, the decoder should set **dwMinNumSurfaces** equal to the optimal number of surfaces needed to decode smoothly. If the renderer cannot allocate that many surfaces, the connection will fail with the error code E_OUTOFMEMORY. The decoder should reconnect with the same media type but set **dwMinNumSurfaces** equal to the minimum number of surfaces required for decoding. For example, the optimal number of surfaces might be 8, while the minimum is 4.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IAMVideoAcceleratorNotify::GetUncompSurfacesInfo](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoacceleratornotify-getuncompsurfacesinfo)