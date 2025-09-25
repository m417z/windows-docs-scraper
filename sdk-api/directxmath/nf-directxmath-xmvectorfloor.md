# XMVectorFloor function

## Description

Computes the floor of each component of an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `V` [in]

Vector for which to compute the floor.

## Return value

Returns a vector whose components are the floor of the corresponding components of *V*.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

**XMVectorFloor** is implemented like this:

``` syntax

XMVECTOR Result;
Result.x = floorf(V.x);
Result.y = floorf(V.y);
Result.z = floorf(V.z);
Result.w = floorf(V.w);
return Result;

```

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)

[XMVectorCeiling](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorceiling)