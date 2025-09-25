# XMQuaternionSquadSetup function

## Description

Provides addresses of setup control points for spherical quadrangle interpolation.

## Parameters

### `pA` [out]

Address of first setup quaternion.

### `pB` [out]

Address of first setup quaternion.

### `pC` [out]

Address of first setup quaternion.

### `Q0` [in]

First quaternion.

### `Q1` [in]

Second quaternion.

### `Q2` [in]

Third quaternion.

### `Q3` [in]

Fourth quaternion.

## Return value

None.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

The results returned in *pA*, *pB*, and *pC* are used as the inputs to the *Q1*,
*Q2*, and *Q3* parameters of
[XMQuaternionSquad](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionsquad).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)

[XMQuaternionSquad](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionsquad)

[XMQuaternionSquadV](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionsquadv)