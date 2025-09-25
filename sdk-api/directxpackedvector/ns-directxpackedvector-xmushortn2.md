# XMUSHORTN2 structure

## Description

A 2D vector for storing unsigned, normalized values as unsigned 16-bit integers, (type
`uint16_t`).

For a list of more functionality such as constructors and operators that are available
using `XMUSHORTN2` when you are programming in C++, see [XMUSHORTN2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmushortn2-extensions).

**Note** See [DirectXMath Library Type
Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Unsigned integer in the range [0, 65536] describing the x-coordinate
of the vector.

### `y`

Unsigned integer in the range [0, 65536] describing the y-coordinate
of the vector.

### `v`

### `XMUSHORTN2`

TBD

### `operator=`

TBD

## Remarks

Those `XMUSHORTN2` constructors using floating point arguments require normalized input,
which must be in the range of [0.0.-1.0]. During instantiation, data is
multiplied by 65535.0f, results are rounded, and then assigned to the appropriate
members of `XMUSHORTN2`.

You can use `XMUSHORTN2` to load instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) from
normalized values by using [XMLoadShortN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadshortn4), which divides each
component 65535.0f, rounds the result, and then assigns the components to an
`XMVECTOR` instance.

You can store `XMVECTOR` instances containing normalized values into `XMUSHORTN2` using [XMStoreShortN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreshortn4), which multiplies each component by 65535.0f
and rounds the result before assigning the values to the appropriate `XMUSHORTN2` members.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMUSHORTN2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmushortn2-extensions)