# IDirect3DDevice9::SetMaterial

## Description

Sets the material properties for the device.

## Parameters

### `pMaterial` [in]

Type: **const [D3DMATERIAL9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmaterial9)***

Pointer to a [D3DMATERIAL9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmaterial9) structure, describing the material properties to set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL if the pMaterial parameter is invalid.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetMaterial](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getmaterial)