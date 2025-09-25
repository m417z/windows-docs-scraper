# XMPlaneTransformStream function

## Description

Transforms a stream of planes by a given matrix.

## Parameters

### `pOutputStream` [out]

Address of the first [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4) in the destination stream. The components of each
**XMFLOAT4** are the plane coefficients (A, B, C, D) for the plane equation
`Ax+By+Cz+D=0`.

### `OutputStride` [in]

Stride, in bytes, between planes in the destination stream.

### `pInputStream` [in]

Address of the first [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4) in the stream to be transformed. The components of each
**XMFLOAT4** are the plane coefficients (A, B, C, D) for the plane equation
`Ax+By+Cz+D=0`.

### `InputStride` [in]

Stride, in bytes, between planes in the input stream.

### `PlaneCount` [in]

Number of planes to transform.

### `M` [in]

Transformation matrix.

## Return value

Returns the address of the first [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4) in the destination stream. The components of
each **XMFLOAT4** are the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Plane Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-plane)

[XMPlaneTransform](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmplanetransform)