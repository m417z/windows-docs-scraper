# XMVectorSqrt function

## Description

Computes the per-component square root of a vector.

## Parameters

### `V` [in]

Vector whose square root is computed.

## Return value

Returns a vector. Each component is the square-root of the corresponding component of *V*.

## Remarks

The square-root operation handles special input values as follows.

| Input Value | Return Value |
| --- | --- |
| +Infinity | +Infinity |
| +0.0f | +0.0f |
| -0.0f | -0.0f |
| < 0.0f | QNaN |

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)

[XMVectorSqrtEst](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorsqrtest)