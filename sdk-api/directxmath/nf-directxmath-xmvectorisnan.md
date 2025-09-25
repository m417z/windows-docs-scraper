# XMVectorIsNaN function

## Description

Performs a per-component NaN test on a vector.

## Parameters

### `V` [in]

Vector to test.

## Return value

Returns a vector containing the results of each component test.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = (V.x == SNaN || V.x == QNaN) ? 0xFFFFFFFF : 0;
Result.y = (V.y == SNaN || V.y == QNaN) ? 0xFFFFFFFF : 0;
Result.z = (V.z == SNaN || V.z == QNaN) ? 0xFFFFFFFF : 0;
Result.w = (V.w == SNaN || V.w == QNaN) ? 0xFFFFFFFF : 0;

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)