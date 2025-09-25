# XMVectorLerpV function

## Description

Performs a linear interpolation between two vectors.

## Parameters

### `V0` [in]

First vector to interpolate from.

### `V1` [in]

Second vector to interpolate from.

### `T` [in]

Interpolating control factor for the corresponding components of the position.

## Return value

Returns a vector containing the interpolation.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = V0.x + T.x * (V1.x - V0.x);
Result.y = V0.y + T.y * (V1.y - V0.y);
Result.z = V0.z + T.z * (V1.z - V0.z);
Result.w = V0.w + T.w * (V1.w - V0.w);

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Geometric Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-geometric)

[XMVectorLerp](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorlerp)