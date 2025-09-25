# XMVectorPow function

## Description

Computes *V1* raised to the power of *V2*.

## Parameters

### `V1` [in]

First vector.

### `V2` [in]

Second vector.

## Return value

Returns a vector. Each component is the corresponding component of *V1* raised to the power of the
corresponding component in *V2*.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = pow(V1.x, V2.x);
Result.y = pow(V1.y, V2.y);
Result.z = pow(V1.z, V2.z);
Result.w = pow(V1.w, V2.w);

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)