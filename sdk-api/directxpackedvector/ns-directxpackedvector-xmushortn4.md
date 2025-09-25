# XMUSHORTN4 structure

## Description

A 4D vector for storing unsigned, normalized values as signed 16-bit integers (type `uint16_t`).

For a list of more functionality such as constructors and operators that are available
using `XMUSHORTN4` when you are programming in C++, see [XMUSHORTN4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmushortn4-extensions).

**Note** See [DirectXMath Library Type
Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Unsigned 16-bit integer in the range [0-65535] describing the x-coordinate
of the vector.

### `y`

Unsigned 16-bit integer in the range [0-65535] describing the y-coordinate
of the vector.

### `z`

Unsigned 16-bit integer in the range [0-65535] describing the z-coordinate
of the vector.

### `w`

Unsigned 16-bit integer in the range [0-65535] describing the w-coordinate
of the vector.

### `v`

### `XMUSHORTN4`

TBD

### `operator=`

TBD

## Remarks

Those `XMUSHORTN4` constructors using floating point arguments require normalized input,
which must be in the range of [0.0-1.0]. During instantiation, data is
multiplied by 65535.0f, results are rounded, and then
assigned to the appropriate members of `XMUSHORTN4`.

You can use `XMUSHORTN4` to load instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) from
normalized values by using [XMLoadUShortN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadushortn4), which divides each
component 65535.0f, rounds the result, and then assigns the components to an
`XMVECTOR` instance.

You can store `XMVECTOR` instances containing normalized values into `XMUSHORTN4` using [XMStoreUShortN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreushortn4), which multiplies each component by 65535.0f,
and then rounds the result before assigning the values to the appropriate `XMUSHORTN4` members.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMUSHORTN4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmushortn4-extensions)