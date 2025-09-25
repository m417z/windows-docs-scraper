# XMVectorLogE function

## Description

Computes the base e logarithm of each component of a vector.The base e logarithm is also known as the natural logarithm.

## Parameters

### `V` [in]

Vector for which to compute the base e logarithm.

## Return value

Returns a vector whose components are base e logarithm of the corresponding components of *V*.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8.1. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

**XMVectorLogE** is new for DirectXMath version 3.05.

It's similar to the existing [XMVectorLog](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorlog) function for Windows 8, but computes base e instead of base 2.

**XMVectorLogE** is implemented like this:

``` syntax

XMVECTOR Result;

Result.x = logf(V.x);
Result.y = logf(V.y);
Result.z = logf(V.z);
Result.w = logf(V.w);

return Result;

```

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorLog2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorlog2)

[XMVectorLog10](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorlog10)

[XMVectorExpE](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexpe)