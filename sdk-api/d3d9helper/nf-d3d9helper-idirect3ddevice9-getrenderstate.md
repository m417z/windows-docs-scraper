# IDirect3DDevice9::GetRenderState

## Description

Retrieves a render-state value for a device.

## Parameters

### `State` [in]

Type: **[D3DRENDERSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3drenderstatetype)**

Device state variable that is being queried. This parameter can be any member of the [D3DRENDERSTATETYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3drenderstatetype) enumerated type.

### `pValue` [out, retval]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a variable that receives the value of the queried render state variable when the method returns.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. D3DERR_INVALIDCALL if one of the arguments is invalid.

## Remarks

This method will not return device state for a device that is created using D3DCREATE_PUREDEVICE. If you want to use this method, you must create your device with any of the other values in [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate)."

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetRenderState](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate)