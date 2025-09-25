# XMScalarACosEst function

## Description

Estimates the arccosine of a floating-point number.

## Parameters

### `Value` [in]

**float** value between -1.0f and 1.0f.

## Return value

Returns the inverse cosine of *Value*.

## Remarks

`Est` functions offer increased performance at the expense of reduced accuracy.
`Est` functions are appropriate for non-critical calculations where accuracy can be sacrificed for speed.
The exact amount of lost accuracy and speed increase are platform dependent.

This function uses a 3-degree minimax approximation.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Scalar Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-scalar)

[XMScalarACos](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmscalaracos)

[XMScalarCos](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmscalarcos)

[XMScalarCosEst](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmscalarcosest)