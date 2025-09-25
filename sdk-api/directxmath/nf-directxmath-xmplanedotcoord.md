# XMPlaneDotCoord function

## Description

Calculates the dot product between an input plane and a 3D vector.

## Parameters

### `P` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation

```
XMVECTOR vectorOut;

vectorOut.x = P.x * V.x + P.y * V.y + P.z * V.z + P.w * 1.0f;
vectorOut.y = P.x * V.x + P.y * V.y + P.z * V.z + P.w * 1.0f;
vectorOut.z = P.x * V.x + P.y * V.y + P.z * V.z + P.w * 1.0f;
vectorOut.w = P.x * V.x + P.y * V.y + P.z * V.z + P.w * 1.0f;

return vectorOut;
```

.

### `V` [in]

3D vector to use in the dot product. The w component of *V* is always treated as if is 1.0f.

## Return value

Returns the dot product between *P* and *V* replicated into each of the four components of the
returned **XMVECTOR**.

## Remarks

This function can be useful in finding the signed distance from a point to a plane. The following pseudocode
demonstrates the operation of the function.

`Ax+By+Cz+D=0`

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Plane Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-plane)