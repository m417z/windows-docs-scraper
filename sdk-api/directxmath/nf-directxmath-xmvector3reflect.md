# XMVector3Reflect function

## Description

Reflects an incident 3D vector across a 3D normal vector.

## Parameters

### `Incident` [in]

3D incident vector to reflect.

### `Normal` [in]

3D normal vector to reflect the incident vector across.

## Return value

Returns the reflected incident angle.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

float s = 2.0f * ( Incident.x * Normal.x + Incident.y * Normal.y + Incident.z * Normal.z );

Result.x = Incident.x - s * Normal.x;
Result.y = Incident.y - s * Normal.y;
Result.z = Incident.z - s * Normal.z;
Result.w = undefined;

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 3D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector3-geometric)