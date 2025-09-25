# XMVector2Cross function

## Description

Computes the 2D cross product.

## Parameters

### `V1` [in]

2D vector.

### `V2` [in]

2D vector.

## Return value

Returns a vector. The 2D cross product is replicated into each component.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = V1.x * V2.y - v1.y * V2.x;
Result.y = V1.x * V2.y - v1.y * V2.x;
Result.z = V1.x * V2.y - v1.y * V2.x;
Result.w = V1.x * V2.y - v1.y * V2.x;

return Result;
```

Note that a 'cross-product' in 2D is not well-defined.
This function computes a geometric cross-product often used in 2D graphics.
[XMVector2Orthogonal](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2orthogonal) is another possible interpretation of a 'cross-product' in 2D.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-geometric)