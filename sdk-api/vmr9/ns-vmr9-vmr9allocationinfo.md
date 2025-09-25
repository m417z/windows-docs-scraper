# VMR9AllocationInfo structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMR9AllocationInfo** structure describes the Direct3D surfaces that a VMR-9 Allocator-Presenter object should allocate.

## Members

### `dwFlags`

Specifies a bitwise combination of flags from the [VMR9SurfaceAllocationFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9surfaceallocationflags) enumeration type.

### `dwWidth`

Specifies the width of the surfaces.

### `dwHeight`

Specifies the height of the surfaces.

### `Format`

Specifies the surface format, as a **D3DFORMAT** type. The value D3DFMT_UNKNOWN (zero) indicates that the surface format should be compatible with the display.

### `Pool`

Specifies the Direct3D memory pool to use for the surfaces, as a **D3DPOOL** type.

### `MinBuffers`

Specifies the minimum number of buffers to create.

### `szAspectRatio`

Specifies the video aspect ratio as a **SIZE** structure.

### `szNativeSize`

Specifies the native video size as a **SIZE** structure.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IVMRSurfaceAllocator9::InitializeDevice](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrsurfaceallocator9-initializedevice)

[IVMRSurfaceAllocatorNotify9::AllocateSurfaceHelper](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrsurfaceallocatornotify9-allocatesurfacehelper)