# XMVectorExp2 function

## Description

Computes two raised to the power for each component.

## Parameters

### `V` [in]

Vector used for the exponents of base two.

## Return value

Returns a vector whose components are two raised to the power of the corresponding component of *V*.

## Remarks

### Platform Requirements

Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

**XMVectorExp2** is new for DirectXMath version 3.05, but it's just a renamed version of the existing [XMVectorExp](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexp) function for Windows 8.

**XMVectorExp2** is implemented like this:

``` syntax

XMVECTOR Result;

Result.x = exp2f(V.x);
Result.y = exp2f(V.y);
Result.z = exp2f(V.z);
Result.w = exp2f(V.w);

return Result;

```

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorExpE](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexpe)

[XMVectorExp10](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexp10)

[XMVectorLog2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorlog2)