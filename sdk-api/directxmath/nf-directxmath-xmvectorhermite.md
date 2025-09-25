# XMVectorHermite function

## Description

Performs a Hermite spline interpolation, using the specified vectors.

## Parameters

### `Position0` [in]

First position to interpolate from.

### `Tangent0` [in]

Tangent vector for the first position.

### `Position1` [in]

Second position to interpolate from.

### `Tangent1` [in]

Tangent vector for the second position.

### `t` [in]

Interpolation control factor.

## Return value

Returns a vector containing the interpolation.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

float t2 = t * t;
float t3 = t2* t;

float P0 = 2.0f * t3 - 3.0f * t2 + 1.0f;
float T0 = t3 - 2.0f * t2 + t;
float P1 = -2.0f * t3 + 3.0f * t2;
float T1 = t3 - t2;

Result.x = P0 * Position0.x + T0 * Tangent0.x + P1 * Position1.x + T1 * Tangent1.x;
Result.y = P0 * Position0.y + T0 * Tangent0.y + P1 * Position1.y + T1 * Tangent1.y;
Result.z = P0 * Position0.z + T0 * Tangent0.z + P1 * Position1.z + T1 * Tangent1.z;
Result.w = P0 * Position0.w + T0 * Tangent0.w + P1 * Position1.w + T1 * Tangent1.w;

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Geometric Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-geometric)

[XMVectorHermiteV](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorhermitev)