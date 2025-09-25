# XMVectorNegativeMultiplySubtract function

## Description

Computes the difference of a third vector and the product of the first two vectors.

## Parameters

### `V1` [in]

Vector multiplier.

### `V2` [in]

Vector multiplicand.

### `V3` [in]

Vector subtrahend.

## Return value

Returns the resulting vector. See the remarks.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR result;

result.x = V3.x - V1.x * V2.x;
result.y = V3.y - V1.y * V2.y;
result.z = V3.z - V1.z * V2.z;
result.w = V3.w - V1.w * V2.w;

return result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)