## Description

Interpolates between four unit quaternions, using spherical quadrangle interpolation.

## Parameters

### `Q0` [in]

First unit quaternion.

### `Q1` [in]

Second unit quaternion.

### `Q2` [in]

Third unit quaternion.

### `Q3` [in]

Fourth unit quaternion.

### `t` [in]

Interpolation control factor.

## Return value

Returns the interpolated quaternion. If *Q0*, *Q1*, *Q2*, and *Q3* are not all unit quaternions, the returned quaternion is undefined.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions, where the X, Y, and Z components are the vector part and the W component is the scalar part.

The use of this method requires some setup before its use. See [XMQuaternionSquadSetup](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmquaternionsquadsetup) for details.

The following example shows how to use a set of quaternion keys (Q0, Q1, Q2, Q3) to compute the inner quadrangle points (A, B, C). This ensures that the tangents are continuous across adjacent segments.

```cpp
// Rotation about the z-axis
XMVECTOR Q0 = XMVectorSet(0,  0, 0.707f, -.707f);
XMVECTOR Q1 = XMVectorSet(0,  0, 0.000f, 1.000f);
XMVECTOR Q2 = XMVectorSet(0,  0, 0.707f, 0.707f);
XMVECTOR Q3 = XMVectorSet(0,  0, 1.000f, 0.000f);

XMVECTOR A, B, C;
XMQuaternionSquadSetup(&A, &B, &C, Q0, Q1, Q2, Q3);

XMVECTOR result = XMQuaternionSquad(Q1, A, B, C, 0.5f);
// result is a rotation of 45 degrees around the z-axis
```

### Platform Requirements

Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

* [DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)

* [XMQuaternionSquadSetup](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmquaternionsquadsetup)

* [XMQuaternionSquadV](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmquaternionsquadv)