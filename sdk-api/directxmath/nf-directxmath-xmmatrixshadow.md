# XMMatrixShadow function

## Description

Builds a transformation matrix that flattens geometry into a plane.

## Parameters

### `ShadowPlane` [in]

Reference plane.

### `LightPosition` [in]

4D vector describing the light's position. If the light's w-component is 0.0f, the ray from the origin to the light represents a directional light. If it is 1.0f, the light is a point light.

## Return value

Returns the transformation matrix that flattens the geometry into the plane *ShadowPlane*.

## Remarks

This function is useful for forming planar-projected shadows from a light source.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Matrix Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-matrix)