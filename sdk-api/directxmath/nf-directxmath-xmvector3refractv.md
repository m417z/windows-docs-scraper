# XMVector3RefractV function

## Description

Refracts an incident 3D vector across a 3D normal vector.

## Parameters

### `Incident` [in]

3D incident vector to refract.

### `Normal` [in]

3D normal vector to refract the incident vector through.

### `RefractionIndex` [in]

3D vector whose x, y, and z-components are equal to the index of refraction.

## Return value

Returns the refracted incident vector. If the refraction index and the angle between the incident vector and the normal
are such that the result is a total internal reflection, the function will return a vector of the form <
0.0f, 0.0f, 0.0f, undefined >.

## Remarks

This function is identical to
[XMVector3Refract](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector3refract) except that the
*RefractionIndex* is supplied using a 3D vector instead of a **float** value.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 3D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector3-geometric)

[XMVector2Refract](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2refract)