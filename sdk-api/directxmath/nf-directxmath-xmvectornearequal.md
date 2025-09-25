# XMVectorNearEqual function

## Description

Performs a per-component test for equality of two vectors within a given threshold.

## Parameters

### `V1` [in]

First vector to compare.

### `V2` [in]

Second vector compare.

### `Epsilon` [in]

Tolerance value used for judging equality.

## Return value

Returns a vector containing the results of each component test.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = (abs(V1.x - V2.x) <= Epsilon) ? 0xFFFFFFFF : 0;
Result.y = (abs(V1.y - V2.y) <= Epsilon) ? 0xFFFFFFFF : 0;
Result.z = (abs(V1.z - V2.z) <= Epsilon) ? 0xFFFFFFFF : 0;
Result.w = (abs(V1.w - V2.w) <= Epsilon) ? 0xFFFFFFFF : 0;

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Comparison Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-comparison)