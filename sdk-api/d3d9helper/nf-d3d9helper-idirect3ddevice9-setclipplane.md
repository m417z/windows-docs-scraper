# IDirect3DDevice9::SetClipPlane

## Description

Sets the coefficients of a user-defined clipping plane for the device.

## Parameters

### `Index` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the clipping plane for which the plane equation coefficients are to be set.

### `pPlane` [in]

Type: **const float***

Pointer to an address of a four-element array of values that represent the clipping plane coefficients to be set, in the form of the general plane equation. See Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value is D3DERR_INVALIDCALL. This error indicates that the value in Index exceeds the maximum clipping plane index supported by the device or that the array at pPlane is not large enough to contain four floating-point values.

## Remarks

The coefficients that this method sets take the form of the general plane equation. If the values in the array at pPlane were labeled A, B, C, and D in the order that they appear in the array, they would fit into the general plane equation so that Ax + By + Cz + Dw = 0. A point with homogeneous coordinates (x, y, z, w) is visible in the half space of the plane if Ax + By + Cz + Dw >= 0. Points that exist behind the clipping plane are clipped from the scene.

When the fixed function pipeline is used the plane equations are assumed to be in world space. When the programmable pipeline is used the plane equations are assumed to be in the clipping space (the same space as output vertices).

This method does not enable the clipping plane equation being set. To enable a clipping plane, set the corresponding bit in the DWORD value applied to the D3DRS_CLIPPLANEENABLE render state.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetClipPlane](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getclipplane)