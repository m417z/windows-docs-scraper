# XMSHORTN4 structure

## Description

A 4D vector for storing signed, normalized values as signed 16-bit integers, (type `int16_t`).

For a list of additional functionality such as constructors and operators that are available
using `XMSHORTN4` when you are programming in C++, see [XMSHORTN4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmshortn4-extensions).

**Note** See [DirectXMath Library Type
Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Signed 16-bit integer in the range [-32767, 32767] describing the x-coordinate
of the vector.

### `y`

Signed 16-bit integer in the range [-32767, 32767] describing the y-coordinate
of the vector.

### `z`

Signed 16-bit integer in the range [-32767, 32767] describing the z-coordinate
of the vector.

### `w`

Signed 16-bit integer in the range [-32767, 32767] describing the w-coordinate
of the vector.

### `v`

### `XMSHORTN4`

TBD

### `operator=`

TBD

## Remarks

Those `XMSHORTN4` constructors using floating point arguments require normalized input,
which must be in the range of [-1.0.-1.0]. During instantiation, these data are
multiplied by 32767.0f, results are rounded, and then
assigned to the appropriate members of `XMSHORTN4`.

`XMSHORTN4` can be used to load instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) from
normalized values, by using [XMLoadShortN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadshortn4), which divides each
component 32767.0f, rounds the result, and then assigns the components to an
`XMVECTOR` instance.

`XMVECTOR` instances containing normalized values can be stored into `XMSHORTN4` using [XMStoreShortN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreshortn4), which multiplies each component by 32767.0f,
rounding the result, before assigning the values to the appropriate `XMSHORTN4` members.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMSHORTN4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmshortn4-extensions)