# XMQuaternionInverse function

## Description

Computes the inverse of a quaternion.

## Parameters

### `Q` [in]

Quaternion to invert.

## Return value

Returns the inverse of *Q*.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

float LengthSq = Q.x * Q.x + Q.y * Q.y + Q.z * Q.z + Q.w * Q.w;

Result.x = -Q.x / LengthSq;
Result.y = -Q.y / LengthSq;
Result.z = -Q.z / LengthSq;
Result.w = Q.w / LengthSq;

return Result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)