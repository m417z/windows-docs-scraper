# IVMRSurfaceAllocator9::GetSurface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetSurface** method gets a Direct3D surface from the allocator-presenter.

## Parameters

### `dwUserID` [in]

Application-defined identifier. This value is the same value that the application passed to the [IVMRSurfaceAllocatorNotify9::AdviseSurfaceAllocator](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrsurfaceallocatornotify9-advisesurfaceallocator) method in the *dwUserID* parameter.

### `SurfaceIndex` [in]

Specifies the index of the surface to retrieve.

### `SurfaceFlags` [in]

Reserved.

### `lplpSurface` [out]

Receives a pointer to the **IDirect3DSurface9** interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRSurfaceAllocator9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrsurfaceallocator9)

[Supplying a Custom Allocator-Presenter for VMR-9](https://learn.microsoft.com/windows/desktop/DirectShow/supplying-a-custom-allocator-presenter-for-vmr-9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)