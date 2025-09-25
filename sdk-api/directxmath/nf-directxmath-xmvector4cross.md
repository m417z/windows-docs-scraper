# XMVector4Cross function

## Description

Computes the 4D cross product.

## Parameters

### `V1` [in]

4D vector.

### `V2` [in]

4D vector.

### `V3` [in]

4D vector.

## Return value

Returns the 4D cross product of *V1*, *V2*, and *V3*.

## Remarks

A 4D cross-product is not well-defined. This function computes a geometric analog to the 3D cross product.
[XMVector4Orthogonal](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4orthogonal) is another generalized 'cross-product' for 4D vectors.

The following pseudocode demonstrates the operation of the function:

```

XMVECTOR Result;

Result.x = V1.y * (V2.z * V3.w - V3.z * V2.w)
           -  V1.z * (V2.y * V3.w - V3.y * V2.w )
           +  V1.w * (V2.y * V3.z - V3.y * V2.z);

Result.y = V1.x * (V3.z * V2.w - V2.z * V3.w)
           - V1.z * (V3.x * V2.w - V2.x * V3.w)
           + V1.w * (V3.x * V2.z - V2.x * V3.z);

Result.z = V1.x * (V2.y * V3.w - V3.y * V2.w)
           - V1.y * (V2.x * V3.w - V3.x * V2.w)
           + V1.w * (V2.x * V3.y - V3.x * V2.y);

Result.w = V1.x * (V3.y * V2.z - V2.y * V3.z)
           - V1.y * (V3.x * V2.z - V2.x * V3.z)
           + V1.z * (V3.x * V2.y - V2.x * V3.y);

return Result;

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-geometric)