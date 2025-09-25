# XMVectorExp10 function

## Description

Computes ten raised to the power for each component.

## Parameters

### `V` [in]

Vector used for the exponents of base ten.

## Return value

Returns a vector whose components are ten raised to the power of the corresponding component of *V*.

## Remarks

### Platform Requirements

Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

> This function was added in DirectXMath 3.16

**XMVectorExp10** is implemented like this:

``` syntax

XMVECTOR Result;

Result.x = powf(10.0f, V.x);
Result.y = powf(10.0f, V.y);
Result.z = powf(10.0f, V.z);
Result.w = powf(10.0f, V.w);

return Result;

```

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorExp2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexp2)

[XMVectorExpE](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexpe)

[XMVectorLog10](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorlog10)