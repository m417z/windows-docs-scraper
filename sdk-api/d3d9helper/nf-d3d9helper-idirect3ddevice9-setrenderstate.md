# IDirect3DDevice9::SetRenderState

## Description

Sets a single device render-state parameter.

## Parameters

### `State` [in]

Type: **[D3DRENDERSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3drenderstatetype)**

Device state variable that is being modified. This parameter can be any member of the [D3DRENDERSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3drenderstatetype) enumerated type.

### `Value` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New value for the device render state to be set. The meaning of this parameter is dependent on the value specified for *State*. For example, if *State* were D3DRS_SHADEMODE, the second parameter would be one member of the [D3DSHADEMODE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dshademode) enumerated type.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if one of the arguments is invalid.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetRenderState](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getrenderstate)

[IDirect3DDevice9::SetTransform](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settransform)