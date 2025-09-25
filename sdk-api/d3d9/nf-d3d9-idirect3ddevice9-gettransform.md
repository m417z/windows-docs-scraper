# IDirect3DDevice9::GetTransform

## Description

Retrieves a matrix describing a transformation state.

## Parameters

### `State` [in]

Type: **[D3DTRANSFORMSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtransformstatetype)**

Device state variable that is being modified. This parameter can be any member of the [D3DTRANSFORMSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtransformstatetype) enumerated type, or the [D3DTS_WORLDMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dts-worldmatrix) macro.

### `pMatrix` [out]

Type: **[D3DMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmatrix)***

Pointer to a
[D3DMATRIX](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmatrix) structure, describing the returned transformation state.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL if one of the arguments is invalid.

## Remarks

This method will not return device state for a device that is created using D3DCREATE_PUREDEVICE. If you want to use this method, you must create your device with any of the other flag values in [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetTransform](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settransform)