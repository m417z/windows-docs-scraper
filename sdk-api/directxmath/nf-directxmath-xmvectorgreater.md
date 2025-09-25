# XMVectorGreater function

## Description

Performs a per-component test for greater-than between two vectors.

## Parameters

### `V1` [in]

First vector to compare.

### `V2` [in]

Second vector to compare.

## Return value

Returns a vector containing the results of each component test.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = (V1.x > V2.x) ? 0xFFFFFFFF : 0;
Result.y = (V1.y > V2.y) ? 0xFFFFFFFF : 0;
Result.z = (V1.z > V2.z) ? 0xFFFFFFFF : 0;
Result.w = (V1.w > V2.w) ? 0xFFFFFFFF : 0;

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Comparison Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-comparison)

[XMVectorGreaterR](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorgreaterr)