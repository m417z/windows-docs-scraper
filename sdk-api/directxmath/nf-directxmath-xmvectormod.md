# XMVectorMod function

## Description

Computes the per-component floating-point remainder of the quotient of two vectors.

## Parameters

### `V1` [in]

Vector dividend.

### `V2` [in]

Vector divisor.

## Return value

Returns a vector whose components are the floating-point remainders of the divisions.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = fmod(V1.x, V2.x);
Result.y = fmod(V1.y, V2.y);
Result.z = fmod(V1.z, V2.z);
Result.w = fmod(V1.w, V2.w);

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)