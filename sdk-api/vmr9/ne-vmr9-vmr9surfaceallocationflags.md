# VMR9SurfaceAllocationFlags enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMR9SurfaceAllocationFlags** enumeration type is used with the [IVMRSurfaceAllocator9::InitializeDevice](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrsurfaceallocator9-initializedevice) method to specify surface creation parameters (VMR-9 only).

## Constants

### `VMR9AllocFlag_3DRenderTarget:0x1`

Indicates that the surface is a Direct3D render target.

### `VMR9AllocFlag_DXVATarget:0x2`

Indicates that the render target supports DXVA.

### `VMR9AllocFlag_TextureSurface:0x4`

Indicates that the target is a Direct3D texture surface.

### `VMR9AllocFlag_OffscreenSurface:0x8`

Indicates an offscreen surface.

### `VMR9AllocFlag_RGBDynamicSwitch:0x10`

In YUV mixing mode, indicates that the mixer can accept RGB formats in addition to the specified YUV format. The allocator-presenter can switch between the formats dynamically. This flag is only valid in YUV mixing mode.

### `VMR9AllocFlag_UsageReserved:0xe0`

Reserved for future use.

### `VMR9AllocFlag_UsageMask:0xff`

Bitwise **OR** of all flags; not used by applications

## Remarks

The VMR9AllocFlag_TextureSurface flag can be combined with the VMR9AllocFlag_DXVATarget and VMR9AllocFlag_3DRenderTarget flags.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)