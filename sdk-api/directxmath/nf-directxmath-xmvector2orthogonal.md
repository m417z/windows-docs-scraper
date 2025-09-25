# XMVector2Orthogonal function

## Description

Computes a vector perpendicular to a 2D vector.

## Parameters

### `V` [in]

2D vector.

## Return value

Returns the 2D vector orthogonal to *V*.

## Remarks

Note that a 'cross-product' in 2D is not well-defined. This function computes a generalized cross-product in 2D.
[XMVector2Cross](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2cross) is another possible interpretation of a 'cross-product' in 2D.

The following pseudocode demonstrates the operation of the function:

```

XMVECTOR Result;

Result.x = -V.y;
Result.y = V.x;
Result.z = 0;
Result.w = 0;

return Result;

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-geometric)