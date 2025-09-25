# IDirect3DDevice9::GetDeviceCaps

## Description

Retrieves the capabilities of the rendering device.

## Parameters

### `pCaps` [out]

Type: **[D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9)***

Pointer to a [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure, describing the returned device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

**IDirect3DDevice9::GetDeviceCaps** retrieves the software vertex pipeline capabilities when the device is being used in software vertex processing mode.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)