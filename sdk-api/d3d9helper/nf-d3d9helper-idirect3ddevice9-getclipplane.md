# IDirect3DDevice9::GetClipPlane

## Description

Retrieves the coefficients of a user-defined clipping plane for the device.

## Parameters

### `Index` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the clipping plane for which the plane equation coefficients are retrieved.

### `pPlane` [out]

Type: **float***

Pointer to a four-element array of values that represent the coefficients of the clipping plane in the form of the general plane equation. See Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value is D3DERR_INVALIDCALL. This error indicates that the value in Index exceeds the maximum clipping plane index supported by the device, or that the array at pPlane is not large enough to contain four floating-point values.

## Remarks

This method will not return device state for a device that is created using D3DCREATE_PUREDEVICE. If you want to use this method, you must create your device with any of the other values in [D3DCREATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dcreate)."

The coefficients that this method reports take the form of the general plane equation. If the values in the array at pPlane were labeled A, B, C, and D in the order that they appear in the array, they would fit into the general plane equation so that Ax + By + Cz + Dw = 0. A point with homogeneous coordinates (x, y, z, w) is visible in the half space of the plane if Ax + By + Cz + Dw >= 0. Points that exist on or behind the clipping plane are clipped from the scene.

The plane equation used by this method exists in world space and is set by a previous call to the [IDirect3DDevice9::SetClipPlane](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setclipplane) method.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetClipPlane](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setclipplane)