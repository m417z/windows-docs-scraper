# IDirect3DDevice9::GetMaterial

## Description

Retrieves the current material properties for the device.

## Parameters

### `pMaterial` [out]

Type: **[D3DMATERIAL9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmaterial9)***

Pointer to a [D3DMATERIAL9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmaterial9) structure to fill with the currently set material properties.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL if the pMaterial parameter is invalid.

## Remarks

This method will not return device state for a device that is created using D3DCREATE_PUREDEVICE. If you want to use this method, you must create your device with any of the other values in [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetMaterial](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setmaterial)