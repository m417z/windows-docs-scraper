# XMVectorMax function

## Description

Makes a per-component comparison between two vectors, and returns a vector containing the largest components.

## Parameters

### `V1` [in]

First vector to compare.

### `V2` [in]

Second vector to compare.

## Return value

Returns a vector containing the largest components between the two vectors.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = (V1.x > V2.x) ? V1.x : V2.x;
Result.y = (V1.y > V2.y) ? V1.y : V2.y;
Result.z = (V1.z > V2.z) ? V1.z : V2.z;
Result.w = (V1.w > V2.w) ? V1.w : V2.w;

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)