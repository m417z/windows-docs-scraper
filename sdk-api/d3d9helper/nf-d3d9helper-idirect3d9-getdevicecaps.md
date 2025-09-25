# IDirect3D9::GetDeviceCaps

## Description

Retrieves device-specific information about a device.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number that denotes the display adapter. D3DADAPTER_DEFAULT is always the primary display adapter.

### `DeviceType` [in]

Type: **[D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype)**

Member of the [D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype) enumerated type. Denotes the device type.

### `pCaps` [out]

Type: **[D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9)***

Pointer to a [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9) structure to be filled with information describing the capabilities of the device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, D3DERR_INVALIDDEVICE, D3DERR_OUTOFVIDEOMEMORY, and D3DERR_NOTAVAILABLE.

## Remarks

The application should not assume the persistence of vertex processing capabilities across Direct3D device objects. The particular capabilities that a physical device exposes may depend on parameters supplied to [CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9-createdevice). For example, the capabilities may yield different vertex processing capabilities before and after creating a Direct3D Device Object with hardware vertex processing enabled. For more information see the description of [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9).

## See also

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)