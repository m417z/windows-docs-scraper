# XMVectorCatmullRom function

## Description

Performs a Catmull-Rom interpolation, using the specified position vectors.

## Parameters

### `Position0` [in]

First position.

### `Position1` [in]

Second position.

### `Position2` [in]

Third position.

### `Position3` [in]

Fourth position.

### `t` [in]

Interpolating control factor.

## Return value

Returns the results of the Catmull-Rom interpolation.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

float t2 = t * t;
float t3 = t2* t;

float P0 = -t3 + 2.0f * t2 - t;
float P1 = 3.0f * t3 - 5.0f * t2 + 2.0f;
float P2 = -3.0f * t3 + 4.0f * t2 + t;
float P3 = t3 - t2;

Result.x = (P0 * Position0.x + P1 * Position1.x + P2 * Position2.x + P3 * Position3.x) * 0.5f;
Result.y = (P0 * Position0.y + P1 * Position1.y + P2 * Position2.y + P3 * Position3.y) * 0.5f;
Result.z = (P0 * Position0.z + P1 * Position1.z + P2 * Position2.z + P3 * Position3.z) * 0.5f;
Result.w = (P0 * Position0.w + P1 * Position1.w + P2 * Position2.w + P3 * Position3.w) * 0.5f;

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Geometric Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-geometric)

[XMVectorCatmullRomV](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorcatmullromv)