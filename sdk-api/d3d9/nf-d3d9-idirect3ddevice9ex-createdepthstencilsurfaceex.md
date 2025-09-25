# IDirect3DDevice9Ex::CreateDepthStencilSurfaceEx

## Description

Creates a depth-stencil surface.

## Parameters

### `Width` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Width of the depth-stencil surface, in pixels.

### `Height` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Height of the depth-stencil surface, in pixels.

### `Format` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type, describing the format of the depth-stencil surface. This value must be one of the enumerated depth-stencil formats for this device.

### `MultiSample` [in]

Type: **[D3DMULTISAMPLE_TYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmultisample-type)**

Member of the [D3DMULTISAMPLE_TYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmultisample-type) enumerated type, describing the multisampling buffer type. This value must be one of the allowed multisample types. When this surface is passed to [IDirect3DDevice9::SetDepthStencilSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setdepthstencilsurface), its multisample type must be the same as that of the render target set by [IDirect3DDevice9::SetRenderTarget](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrendertarget).

### `MultisampleQuality` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Quality level. The valid range is between zero and one less than the level returned by pQualityLevels used by [IDirect3D9::CheckDeviceMultiSampleType](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-checkdevicemultisampletype). Passing a larger value returns the error D3DERR_INVALIDCALL. The MultisampleQuality values of paired render targets, depth stencil surfaces, and the MultiSample type must all match.

### `Discard` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set this flag to **TRUE** to enable z-buffer discarding, and **FALSE** otherwise.
If this flag is set, the contents of the depth stencil buffer will be invalid after calling either [IDirect3DDevice9::Present](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-present) or [IDirect3DDevice9::SetDepthStencilSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setdepthstencilsurface) with a different depth surface.

This flag has the same behavior as the constant, D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL, in [D3DPRESENTFLAG](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresentflag).

### `ppSurface` [out, retval]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)****

Address of a pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface, representing the created depth-stencil surface resource.

### `pSharedHandle` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Reserved. Set this parameter to **NULL**. This parameter can be used in Direct3D 9 for Windows Vista to [share resources](https://learn.microsoft.com/windows/desktop/direct3d9/dx9lh).

### `Usage` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of one or more [D3DUSAGE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage) constants which can be OR'd together. Value of 0 indicates no usage.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_NOTAVAILABLE, D3DERR_INVALIDCALL, D3DERR_OUTOFVIDEOMEMORY, E_OUTOFMEMORY.

## Remarks

The memory class of the depth-stencil buffer is always D3DPOOL_DEFAULT.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)