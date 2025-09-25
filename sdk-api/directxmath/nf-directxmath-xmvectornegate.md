# XMVectorNegate function

## Description

Computes the negation of a vector.

## Parameters

### `V` [in]

Vector to negate.

## Return value

Returns the negation of the vector.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR result;

result.x = -V.x;
result.y = -V.y;
result.z = -V.z;
result.w = -V.w;

return result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)