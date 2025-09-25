# IDirect3DDevice9::GetCreationParameters

## Description

Retrieves the creation parameters of the device.

## Parameters

### `pParameters` [out]

Type: **[D3DDEVICE_CREATION_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevice-creation-parameters)***

Pointer to a [D3DDEVICE_CREATION_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevice-creation-parameters) structure, describing the creation parameters of the device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.

D3DERR_INVALIDCALL is returned if the argument is invalid.

## Remarks

You can query the AdapterOrdinal member of the returned [D3DDEVICE_CREATION_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevice-creation-parameters) structure to retrieve the ordinal of the adapter represented by this device.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)