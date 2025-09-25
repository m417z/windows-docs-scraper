# XMVectorAndCInt function

## Description

Computes the logical AND of one vector with the negation of a second vector, treating each component as an unsigned integer.

## Parameters

### `V1` [in]

First vector.

### `V2` [in]

Second vector.

## Return value

Returns a vector whose components are the logical AND of each of the components of *V1* with the negation of the corresponding components of *V2*.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = V1.x & ~V2.x;
Result.y = V1.y & ~V2.y;
Result.z = V1.z & ~V2.z;
Result.w = V1.w & ~V2.w;

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Bit-Wise Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-bit-wise)

[XMVectorAndInt](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorandint)