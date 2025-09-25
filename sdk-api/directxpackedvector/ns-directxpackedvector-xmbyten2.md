# XMBYTEN2 structure

## Description

A 2D vector for storing signed, normalized values as signed 8-bits (1 byte) integers.

For a list of additional functionality such as constructors and operators that are available using `XMBYTEN2` when you
are programming in C++, see [XMBYTEN2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmbyten2-extensions).

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about
equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat),and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Signed 8-bit integer value in the range [-127, 127] describing the x-coordinate of the vector.

### `y`

Signed 8-bit integer value in the range [-127, 127] describing the y-coordinate of the vector.

### `v`

### `XMBYTEN2`

TBD

### `operator=`

TBD

## Remarks

Those `XMBYTEN2` constructors using floating point arguments require normalized input, which must be in the range of
[0.0.-1.0]. During instantiation, this data is multiplied by 127.0f, results are rounded, and then assigned to the
appropriate members of `XMBYTEN2`.

`XMBYTEN2` can be used to load instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) from normalized values,
by using [XMLoadByteN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadbyten2), which divides each component 127.0f, rounds the result,
and then assigns the components to an `XMVECTOR` instance.

`XMVECTOR` instances containing normalized values can be stored into `XMBYTEN2` using
[XMStoreByteN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstorebyten2), which multiplies each component by 127.0f, rounding the result, before assigning
the values to the appropriate `XMBYTEN2` members.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMBYTEN2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmbyten2-extensions)