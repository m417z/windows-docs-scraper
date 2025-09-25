# XMVector4Refract function

## Description

Refracts an incident 4D vector across a 4D normal vector.

## Parameters

### `Incident` [in]

4D incident vector to refract.

### `Normal` [in]

4D normal vector to refract the incident vector through.

### `RefractionIndex` [in]

Index of refraction. See remarks.

## Return value

Returns the refracted incident vector. If the refraction index and the angle between the incident vector and the normal are such that the result is a total internal reflection, the function will return a vector of the form < 0.0f, 0.0f, 0.0f, 0.0f >.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

float t = dot(Incident, Normal);
float r = 1.0f - RefractionIndex * RefractionIndex * (1.0f - t * t);

if (r < 0.0f) // Total internal reflection
{
	Result.x = 0.0f;
	Result.y = 0.0f;
	Result.z = 0.0f;
	Result.w = 0.0f;
}
else
{
	float s = RefractionIndex * t + sqrt(r);
	Result.x = RefractionIndex * Incident.x - s * Normal.x;
	Result.y = RefractionIndex * Incident.y - s * Normal.y;
	Result.z = RefractionIndex * Incident.z - s * Normal.z;
	Result.w = RefractionIndex * Incident.w - s * Normal.w;
}

return Result;
```

The index of refraction is the ratio of the index of refraction of the medium containing the incident vector to the index of refraction of the medium being entered (where the index of refraction of a medium is itself the ratio of the speed of light in a vacuum to the speed of light in the medium).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-geometric)

[XMVector4RefractV](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4refractv)