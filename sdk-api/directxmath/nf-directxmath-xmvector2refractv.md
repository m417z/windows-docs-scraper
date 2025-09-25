# XMVector2RefractV function

## Description

Refracts an incident 2D vector across a 2D normal vector.

## Parameters

### `Incident` [in]

2D incident vector to refract.

### `Normal` [in]

2D normal vector to refract the incident vector through.

### `RefractionIndex` [in]

2D vector whose x and y-components are both equal to the index of refraction.

## Return value

Returns the refracted incident vector. If the refraction index and the angle between the incident vector and the normal are such that the result is a total internal reflection, the function will return a vector of the form < 0.0f, 0.0f, undefined, undefined >.

## Remarks

This function is identical to [XMVector2Refract](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2refract) except that the *RefractionIndex* is supplied using a 2D vector instead of a **float** value.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-geometric)

[XMVector2Refract](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2refract)