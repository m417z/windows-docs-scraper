# XMVector3TransformCoordStream function

## Description

Transforms a stream of 3D vectors by a given matrix, projecting the resulting vectors such that their w coordinates are
equal to 1.0.

## Parameters

### `pOutputStream` [out]

Address of the first [XMFLOAT3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3) in the destination stream.

### `OutputStride` [in]

Stride, in bytes, between vectors in the destination stream.

### `pInputStream` [in]

Address of the first [XMFLOAT3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3) in the stream to be transformed.

### `InputStride` [in]

Stride, in bytes, between vectors in the input stream.

### `VectorCount` [in]

Number of vectors to transform.

### `M` [in]

Transformation matrix.

## Return value

Returns the address of the first [XMFLOAT3](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat3) in the destination stream.

## Remarks

`XMVector3TransformCoordStream` ignores the w component of the input vector, and uses a value of 1.0 instead. The w component of the returned vectors will always be 1.0.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 3D Vector Transformation Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector3-transformation)

[XMVector3TransformCoord](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector3transformcoord)