# XMVectorCeiling function

## Description

Computes the ceiling of each component of an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `V` [in]

Vector for which to compute the ceiling.

## Return value

Returns a vector whose components are the ceiling of the corresponding components of *V*.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

**XMVectorCeiling** is implemented like this:

``` syntax

XMVECTOR Result;
Result.x = ceilf(V.x);
Result.y = ceilf(V.y);
Result.z = ceilf(V.z);
Result.w = ceilf(V.w);
return Result;

```

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)

[XMVectorFloor](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorfloor)