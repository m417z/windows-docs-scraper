# XMPlaneNormalize function

## Description

Normalizes the coefficients of a plane so that coefficients of x, y, and z form a unit normal vector.

## Parameters

### `P` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation

```
XMVECTOR Result;

float LengthSq = P.x * P.x + P.y * P.y + P.z * P.z;

float ReciprocalLength = 1.0f / sqrt(LengthSq);
Result.x = P.x * ReciprocalLength;
Result.y = P.y * ReciprocalLength;
Result.z = P.z * ReciprocalLength;
Result.w = P.w * ReciprocalLength;

return Result;
```

.

## Return value

Returns the normalized plane as a 4D vector whose components are the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

## Remarks

The following pseudocode demonstrates the operation of the function:

`Ax+By+Cz+D=0`

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Plane Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-plane)

[XMPlaneNormalizeEst](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmplanenormalizeest)