# XMVectorLog10 function

## Description

Computes the base ten logarithm of each component of a vector.

## Parameters

### `V` [in]

Vector for which to compute the base ten logarithm.

## Return value

Returns a vector whose components are base ten logarithm of the corresponding components of *V*.

## Remarks

### Platform Requirements

Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

> This function was added in DirectXMath 3.16

**XMVectorLog10** is implemented like this:

``` syntax

XMVECTOR Result;

Result.x = log10f(V.x);
Result.y = log10f(V.y);
Result.z = log10f(V.z);
Result.w = log10f(V.w);

return Result;

```

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorLogE](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorloge)

[XMVectorLog2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorlog2)

[XMVectorExp10](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexp10)