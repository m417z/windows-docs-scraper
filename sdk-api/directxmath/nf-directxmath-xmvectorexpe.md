# XMVectorExpE function

## Description

Computes e (~2.71828) raised to the power for each component.

## Parameters

### `V` [in]

Vector used for the exponents of base e.

## Return value

Returns a vector whose components are e raised to the power of the corresponding component of *V*.

## Remarks

### Platform Requirements

Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

**XMVectorExpE** is new for DirectXMath version 3.05.

It's similar to the existing [XMVectorExp](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexp) function for Windows 8, but computes base e instead of base 2.

**XMVectorExpE** is implemented like this:

``` syntax

XMVECTOR Result;

Result.x = expf(V.x);
Result.y = expf(V.y);
Result.z = expf(V.z);
Result.w = expf(V.w);

return Result;

```

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorExp2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexp2)

[XMVectorExp10](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorexp10)

[XMVectorLogE](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorloge)