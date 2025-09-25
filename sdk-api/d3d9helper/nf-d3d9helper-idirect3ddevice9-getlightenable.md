# IDirect3DDevice9::GetLightEnable

## Description

Retrieves the activity status - enabled or disabled - for a set of lighting parameters within a device.

## Parameters

### `Index` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index of the set of lighting parameters that are the target of this method.

### `pEnable` [out, retval]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a variable to fill with the status of the specified lighting parameters. After the call, a nonzero value at this address indicates that the specified lighting parameters are enabled; a value of 0 indicates that they are disabled.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

This method will not return device state for a device that is created using D3DCREATE_PUREDEVICE. If you want to use this method, you must create your device with any of the other values in [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate).

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetLight](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getlight)

[IDirect3DDevice9::LightEnable](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-lightenable)

[IDirect3DDevice9::SetLight](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setlight)