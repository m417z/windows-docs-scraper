# IDirect3DVolume9::GetDesc

## Description

Retrieves a description of the volume.

## Parameters

### `pDesc` [out]

Type: **[D3DVOLUME_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvolume-desc)***

Pointer to a [D3DVOLUME_DESC](https://learn.microsoft.com/windows/desktop/direct3d9/d3dvolume-desc) structure, describing the volume.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL is returned if the argument is invalid.

## See also

[IDirect3DVolume9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvolume9)