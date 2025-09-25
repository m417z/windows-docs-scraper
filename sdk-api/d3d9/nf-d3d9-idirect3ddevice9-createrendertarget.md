# IDirect3DDevice9::CreateRenderTarget

## Description

Creates a render-target surface.

## Parameters

### `Width` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Width of the render-target surface, in pixels.

### `Height` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Height of the render-target surface, in pixels.

### `Format` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, describing the format of the render target.

### `MultiSample` [in]

Type: **[D3DMULTISAMPLE_TYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmultisample-type)**

Member of the [D3DMULTISAMPLE_TYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmultisample-type) enumerated type, which describes the multisampling buffer type. This parameter specifies the antialiasing type for this render target. When this surface is passed to [IDirect3DDevice9::SetRenderTarget](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrendertarget), its multisample type must be the same as that of the depth-stencil set by [IDirect3DDevice9::SetDepthStencilSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setdepthstencilsurface).

### `MultisampleQuality` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Quality level. The valid range is between zero and one less than the level returned by pQualityLevels used by [IDirect3D9::CheckDeviceMultiSampleType](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-checkdevicemultisampletype). Passing a larger value returns the error, D3DERR_INVALIDCALL. The MultisampleQuality values of paired render targets, depth stencil surfaces, and the multisample type must all match.

### `Lockable` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Render targets are not lockable unless the application specifies **TRUE** for Lockable.

Note that lockable render targets reduce performance on some graphics hardware. The readback performance (moving data from video memory to system memory) depends on the type of hardware used (AGP vs. PCI Express) and is usually far lower than upload performance (moving data from system to video memory). If you need read access to render targets, use [GetRenderTargetData](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getrendertargetdata) instead of lockable render targets.

### `ppSurface` [out, retval]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)****

Address of a pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface.

### `pSharedHandle` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Reserved. Set this parameter to **NULL**. This parameter can be used in Direct3D 9 for Windows Vista to [share resources](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_NOTAVAILABLE, D3DERR_INVALIDCALL, D3DERR_OUTOFVIDEOMEMORY, E_OUTOFMEMORY.

## Remarks

Render-target surfaces are placed in the D3DPOOL_DEFAULT memory class.

The creation of lockable, multisampled render targets is not supported.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)