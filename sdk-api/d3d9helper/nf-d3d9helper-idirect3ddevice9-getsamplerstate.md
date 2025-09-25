# IDirect3DDevice9::GetSamplerState

## Description

Gets the sampler state value.

## Parameters

### `Sampler` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The sampler stage index.

### `Type` [in]

Type: **[D3DSAMPLERSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dsamplerstatetype)**

This parameter can be any member of the [D3DSAMPLERSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dsamplerstatetype) enumerated type.

### `pValue` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

State value to get. The meaning of this value is determined by the Type parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

This method will not return device state for a device that is created using D3DCREATE_PUREDEVICE. If you want to use this method, you must create your device with any of the other values in [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate)."

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetSamplerState](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setsamplerstate)