# XMVectorLog2 function

## Description

Computes the base two logarithm of each component of a vector.

## Parameters

### `V` [in]

Vector for which to compute the base two logarithm.

## Return value

Returns a vector whose components are base two logarithm of the corresponding components of *V*.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8.1. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

**XMVectorLog2** is new for DirectXMath version 3.05, but it's just a renamed version of the existing [XMVectorLog](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorlog) function for Windows 8.

**XMVectorLog2** is implemented like this:

``` syntax

XMVECTOR Result;

Result.x = log2f(V.x);
Result.y = log2f(V.y);
Result.z = log2f(V.z);
Result.w = log2f(V.w);

return Result;

```

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorLogE](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorloge)

[XMVectorLog10](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorlog10)

[XMVectorExp2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexp2)