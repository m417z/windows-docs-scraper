# XMVectorMultiplyAdd function

## Description

Computes the product of the first two vectors added to the third vector.

## Parameters

### `V1` [in]

Vector multiplier.

### `V2` [in]

Vector multiplicand.

### `V3` [in]

Vector addend.

## Return value

Returns the product-sum of the vectors.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = V1.x * V2.x + V3.x;
Result.y = V1.y * V2.y+ V3.y;
Result.z = V1.z * V2.z+ V3.z;
Result.w = V1.w * V2.w+ V3.w;

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)