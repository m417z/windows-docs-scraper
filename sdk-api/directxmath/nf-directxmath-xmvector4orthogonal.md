# XMVector4Orthogonal function

## Description

Computes a vector perpendicular to a 4D vector.

## Parameters

### `V` [in]

4D vector.

## Return value

Returns the 4D vector orthogonal to *V*.

## Remarks

A 4D cross-product is not well-defined. This function computes a generalized 'cross-product' for 4D vectors.
[XMVector4Cross](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4cross) is another geometric 'cross-product' for 4D vectors.

The following pseudocode demonstrates the operation of the function:

```

XMVECTOR Result;

Result.x = V.z;
Result.y = V.w;
Result.z = -V.x;
Result.w = -V.y;

return Result;

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-geometric)