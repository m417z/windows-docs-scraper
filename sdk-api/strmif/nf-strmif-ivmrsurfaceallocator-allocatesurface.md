# IVMRSurfaceAllocator::AllocateSurface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AllocateSurface` method allocates a DirectDraw surface.

## Parameters

### `dwUserID` [in]

An application-defined DWORD_PTR cookie that uniquely identifies this instance of the VMR for use in scenarios when one instance of the allocator-presenter is used with multiple VMR instances.

### `lpAllocInfo` [in]

Specifies the [VMRALLOCATIONINFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmrallocationinfo) structure. See Remarks.

### `lpdwActualBuffers` [in]

[out] On input this parameter is used to request the number of buffers desired. On output it receives the actual number of buffers created.

### `lplpSurface` [out]

Address of a pointer that receives the Direct3D surface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

| Return code | Description |
| --- | --- |
| **E_POINTER** | One of the pointers is invalid. |
| **E_INVALIDARG** | In *dwFlags*, the AMAP_3D_TARGET was combined with AMAP_FORCE_SYSMEM or AMAP_ALLOW_SYSMEM. |
| **E_FAIL** | One or more members of the BITMAPINFOHEADER structure specified by *lpAllocInfo*->lpHdr is incorrect. |

## Remarks

Before calling **AllocateSurface** explicitly, a client application should call [IVMRSurfaceAllocator::FreeSurface](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrsurfaceallocator-freesurface) to be sure that the DirectDraw decoding surface front buffer is **NULL**. If it is not **NULL** at the time an application calls **AllocateSurface**, the debug version of quartz.dll will cause an assertion.

When implementing this method in a custom allocator-presenter, you must examine the value of *lpAllocInfo*->lpHdr->biBitCount. If biBitCount is zero, then you must set it to the pixel depth for the current display. If BiBitCount is left at zero, the surface allocation will fail and a new (default) VMR will be created.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRSurfaceAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrsurfaceallocator)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)