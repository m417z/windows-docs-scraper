# VMRSurfaceAllocationFlags enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMRSurfaceAllocationFlags** enumeration is used with the [IVMRSurfaceAllocator::AllocateSurface](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrsurfaceallocator-allocatesurface) method to specify surface creation parameters.

## Constants

### `AMAP_PIXELFORMAT_VALID:0x1`

Indicates that the **lpPxFmt** field contains valid data that should be used to create the DirectDraw surface.

### `AMAP_3D_TARGET:0x2`

Indicates that the DirectDraw surface created should also be a Direct3D render target that is created with the **DDSCAPS_3DDEVICE** flag set.

### `AMAP_ALLOW_SYSMEM:0x4`

Indicates that if you can't allocate the DirectDraw surface in video memory you will try to allocate a system memory DirectDraw surface. (Note you should never allocate an AGP memory surface.)

### `AMAP_FORCE_SYSMEM:0x8`

Force the surface to be created in system memory. Specify this if you will use GDI to process the image before it is rendered. The surface must match the current monitor display format (pixel depth).

### `AMAP_DIRECTED_FLIP:0x10`

Means that when Flip is called you should Flip to the specified DirectDraw Surface passed as a parameter to the [PresentImage](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrimagepresenter-presentimage) method in the [IVMRImagePresenter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrimagepresenter) interface. Correct support for this flag is crucial in order to keep DXVA buffers seen by a video decoder in sync with the DXVA buffers seen by the graphics driver.

### `AMAP_DXVA_TARGET:0x20`

Indicates that this surface will be used as a DXVA target.

## Remarks

AMAP_3D_TARGET cannot be combined with AMAP_FORCE_SYSMEM or AMAP_ALLOW_SYSMEM because 3D surfaces cannot be created in system memory.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IVMRSurfaceAllocator::AllocateSurface](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrsurfaceallocator-allocatesurface)