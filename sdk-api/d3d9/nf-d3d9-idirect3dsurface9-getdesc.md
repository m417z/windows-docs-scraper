# IDirect3DSurface9::GetDesc

## Description

Retrieves a description of the surface.

## Parameters

### `pDesc` [out]

Type: **[D3DSURFACE_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dsurface-desc)***

Pointer to a [D3DSURFACE_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dsurface-desc) structure, describing the surface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.

D3DERR_INVALIDCALL is returned if the argument is invalid.

## See also

[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)