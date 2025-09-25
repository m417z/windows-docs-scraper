# XMVector3ComponentsFromNormal function

## Description

Using a reference normal vector, splits a 3D vector into components that are parallel and perpendicular to the normal.

## Parameters

### `pParallel` [out]

Address of the component of *V* that is parallel to *Normal*.

### `pPerpendicular` [out]

Address of the component of *V* that is perpendicular to *Normal*.

### `V` [in]

3D vector to break into components.

### `Normal` [in]

3D reference normal vector.

## Return value

None.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 3D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector3-geometric)