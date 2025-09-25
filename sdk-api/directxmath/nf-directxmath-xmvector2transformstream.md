# XMVector2TransformStream function

## Description

Transforms a stream of 2D vectors by a given matrix.

## Parameters

### `pOutputStream` [out]

Address of the first [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4) in the destination stream.

### `OutputStride` [in]

Stride, in bytes, between vectors in the destination stream.

### `pInputStream` [in]

Address of the first [XMFLOAT2](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat2) in the stream to be transformed.

### `InputStride` [in]

Stride, in bytes, between vectors in the input stream.

### `VectorCount` [in]

Number of vectors to transform.

### `M` [in]

Transformation matrix.

## Return value

Returns the address of the first [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4) in the destination stream.

## Remarks

`XMVector2TransformStream` performs transformations by using the input matrix rows 0 and 1 for rotation and scaling, and row 3 for
translation (effectively assuming row 2 is 0). The w component of the input vector is assumed to be 0.
The z component of the output vector should be ignored and its w component may be non-homogeneous (!= 1.0).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Transformation Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-transformation)

[XMVector2Transform](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2transform)