# XMPlaneNearEqual function

## Description

Determines whether two planes are nearly equal.

## Parameters

### `P1` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

### `P2` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

### `Epsilon` [in]

**An XMVECTOR** that gives the component-wise tolerance to use when comparing *P1* and *P2*.

## Return value

Returns **true** if *P1* is nearly equal to *P2* and **false** otherwise.

## Remarks

The `XMPlaneNearEqual` function normalizes the *P1* and *P2* parameters before passing them, and the *Epsilon* parameter, to the [XMVector4NearEqual](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4nearequal) function. For more information about how the calculation is performed, see the **XMVector4NearEqual** function.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Plane Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-plane)