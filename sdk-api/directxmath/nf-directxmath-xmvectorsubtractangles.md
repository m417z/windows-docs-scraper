# XMVectorSubtractAngles function

## Description

Subtracts two vectors representing angles.

## Parameters

### `V1` [in]

First vector of angles. Each angle must satisfy -XM_PI <= *V1* < XM_PI.

### `V2` [in]

Second vector of angles. Each angle must satisfy -XM_2PI <= *V1* < XM_2PI.

## Return value

Returns a vector whose components are the differences of the angles of the corresponding components. Each component of the returned vector will be an angle less than XM_PI and greater than or equal to -XM_PI.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)