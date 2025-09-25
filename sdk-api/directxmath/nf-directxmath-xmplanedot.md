# XMPlaneDot function

## Description

Calculates the dot product between an input plane and a 4D vector.

## Parameters

### `P` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

### `V` [in]

4D vector to use in the dot product.

## Return value

Returns the dot product of *P* and *V* replicated into each of the four components of the returned
**XMVECTOR**.

## Remarks

The **XMPlaneDot** function is useful for determining the
plane's relationship with a homogeneous coordinate. For example, this function can be used to determine if a
particular coordinate is on a particular plane, or on which side of a particular plane a particular coordinate lies.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Plane Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-plane)