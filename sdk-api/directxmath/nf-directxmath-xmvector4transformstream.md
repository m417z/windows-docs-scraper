# XMVector4TransformStream function

## Description

Transforms a stream of 4D vectors by a given matrix.

## Parameters

### `pOutputStream` [out]

Address of the first [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4) in the destination stream.

### `OutputStride` [in]

Stride, in bytes, between vectors in the destination stream.

### `pInputStream` [in]

Address of the first [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4) in the stream to be transformed.

### `InputStride` [in]

Stride, in bytes, between vectors in the input stream.

### `VectorCount` [in]

Number of vectors to transform.

### `M` [in]

Transformation matrix.

## Return value

Returns the address of the first [XMFLOAT4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4) in the destination stream.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Transformation Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-transformation)

[XMVector4Transform](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4transform)