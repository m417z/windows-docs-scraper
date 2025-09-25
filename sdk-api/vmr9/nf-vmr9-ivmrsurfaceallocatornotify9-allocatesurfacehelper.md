# IVMRSurfaceAllocatorNotify9::AllocateSurfaceHelper

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AllocateSurfaceHelper` method allocates a Direct3D surface based on application-specified parameters.

If you are implementing a custom allocator-presenter for the VMR-9, you can use this method to allocate the surfaces.

## Parameters

### `lpAllocInfo` [in]

Pointer to a [VMR9AllocationInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9allocationinfo) structure that describes the surfaces to create.

### `lpNumBuffers` [in, out]

On input, this parameter specifies the number of surfaces to create. On output, this parameter contains the number of surfaces that the method created.

### `lplpSurface` [out]

Address of an array of **IDirect3DSurface9** interface pointers. The size of the array must equal the value in *lpNumBuffers*. The method fills the array with valid **IDirect3DSurface9** pointers for each Direct3D surface that it creates. The caller must release the interface pointers. (Do not put any valid pointers into the array before you call this method, because the method will overwrite them, causing a memory leak.)

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRSurfaceAllocatorNotify9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrsurfaceallocatornotify9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)