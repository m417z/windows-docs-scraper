# IDirect3DDevice9::SetTransform

## Description

Sets a single device transformation-related state.

## Parameters

### `State` [in]

Type: **[D3DTRANSFORMSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtransformstatetype)**

Device-state variable that is being modified. This parameter can be any member of the [D3DTRANSFORMSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtransformstatetype) enumerated type, or the [D3DTS_WORLDMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dts-worldmatrix) macro.

### `pMatrix` [in]

Type: **const [D3DMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmatrix)***

Pointer to a [D3DMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmatrix) structure that modifies the current transformation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if one of the arguments is invalid.

## See also

[D3DTS_WORLD](https://learn.microsoft.com/windows/desktop/direct3d9/d3dts-world)

[D3DTS_WORLDMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dts-worldmatrix)

[D3DTS_WORLDn](https://learn.microsoft.com/windows/desktop/direct3d9/d3dts-worldn)

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetTransform](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-gettransform)

[IDirect3DDevice9::SetRenderState](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate)