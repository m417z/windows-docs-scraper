# XMVectorLerp function

## Description

Performs a linear interpolation between two vectors.

## Parameters

### `V0` [in]

First vector to interpolate from.

### `V1` [in]

Second vector to interpolate from.

### `t` [in]

Interpolation control factor.

## Return value

Returns a vector containing the interpolation.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.x = V0.x + t * (V1.x - V0.x);
Result.y = V0.y + t * (V1.y - V0.y);
Result.z = V0.z + t * (V1.z - V0.z);
Result.w = V0.w + t * (V1.w - V0.w);

return Result;
```

Note it is fairly simple to use this function for doing a cubic interpolation instead of a linear interpolation as
follows:

```

XMVECTOR SmoothStep( XMVECTOR V0, XMVECTOR V1, float t )
{
    t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t);  // Clamp value to 0 to 1
    t = t*t*(3.f - 2.f*t);
    return XMVectorLerp( V0, V1, t );
}

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Geometric Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-geometric)

[XMVectorLerpV](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorlerpv)