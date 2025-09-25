# XMQuaternionMultiply function

## Description

Computes the product of two quaternions.

## Parameters

### `Q1` [in]

First quaternion.

### `Q2` [in]

Second quaternion.

## Return value

Returns the product of two quaternions as *Q2***Q1*.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

The result represents the rotation Q1 followed by the rotation Q2 to be consistent with XMMatrixMulplity
concatenation since this function is typically used to concatenate quaternions that represent rotations (i.e. it returns Q2*Q1).

This function computes the equivalent to the following pseudo-code:

```

XMVECTOR Result;
Result.x = (Q2.w * Q1.x) + (Q2.x * Q1.w) + (Q2.y * Q1.z) - (Q2.z * Q1.y);
Result.y = (Q2.w * Q1.y) - (Q2.x * Q1.z) + (Q2.y * Q1.w) + (Q2.z * Q1.x);
Result.z = (Q2.w * Q1.z) + (Q2.x * Q1.y) - (Q2.y * Q1.x) + (Q2.z * Q1.w);
Result.w = (Q2.w * Q1.w) - (Q2.x * Q1.x) - (Q2.y * Q1.y) - (Q2.z * Q1.z);
return Result;

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)