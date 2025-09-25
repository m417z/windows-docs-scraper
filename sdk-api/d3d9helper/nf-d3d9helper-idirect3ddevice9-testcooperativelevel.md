# IDirect3DDevice9::TestCooperativeLevel

## Description

Reports the current cooperative-level status of the Direct3D device for a windowed or full-screen application.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK, indicating that the device is operational and the calling application can continue.
If the method fails, the return value can be one of the following values: D3DERR_DEVICELOST, D3DERR_DEVICENOTRESET, D3DERR_DRIVERINTERNALERROR.

## Remarks

If the device is lost but cannot be restored at the current time, **IDirect3DDevice9::TestCooperativeLevel** returns the D3DERR_DEVICELOST return code. This would be the case, for example, when a full-screen device has lost focus. If an application detects a lost device, it should pause and periodically call **IDirect3DDevice9::TestCooperativeLevel** until it receives a return value of D3DERR_DEVICENOTRESET. The application may then attempt to reset the device by calling [IDirect3DDevice9::Reset](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-reset) and, if this succeeds, restore the necessary resources and resume normal operation. Note that [IDirect3DDevice9::Present](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-present) will return D3DERR_DEVICELOST if the device is either "lost" or "not reset".

A call to **IDirect3DDevice9::TestCooperativeLevel** will fail if called on a different thread than that used to create the device being reset.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)