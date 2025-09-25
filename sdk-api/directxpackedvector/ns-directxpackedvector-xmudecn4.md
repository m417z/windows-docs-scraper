# XMUDECN4 structure

## Description

A 4D vector for storing unsigned, normalized integer values as 10 bit unsigned x-, y-,
and z-components and a 2-bit unsigned w-component.

For a list of more functionality such as constructors and operators that are available
using `XMUDECN4` when you are programming in C++, see [XMUDECN4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmudecn4-extensions).

**Note** See [DirectXMath Library Type
Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Unsigned integer value in the range [0, 1023] describing the
x-coordinate of the vector.

### `y`

Unsigned integer value in the range [0, 1023] describing the
y-coordinate of the vector.

### `z`

Unsigned integer value in the range [0, 1023] describing the
z-coordinate of the vector.

### `w`

Unsigned integer value in the range [0, 3] describing the w-coordinate
of the vector.

### `v`

Unsigned 32-bit integer representing the 4D vector.

### `XMUDECN4`

TBD

### `operator` uint32_t

TBD

### `operator=`

TBD

## Remarks

Those `XMUDECN4` constructors using floating point arguments require normalized input,
which must be in the range of [0.-1.0]. During instantiation, the inputs specifying the x-, y-,
and z-components are multiplied by 1023.0f, and the w-component are multiplied by 3.0f.
The results are rounded, and then assigned to the appropriate members of `XMUDECN4`.

You can use `XMUDECN4` to load instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) from normalized values
by using [XMLoadUDecN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadudecn4), which divides the x-, y-, and
z-components by 1023.0f, divides the w-component by 3.0f, rounds the result, and then assigns
the components to an `XMVECTOR` instance.

`XMVECTOR` instances containing normalized values can be stored into `XMUDECN4` using [XMStoreUDecN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreudecn4), which multiplies the x-, y-, and z-components by
1023.0f, multiplies the w-component by 3.0f, and rounds the result before assigning the values
to the appropriate `XMUDECN4` members.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMUDECN4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmudecn4-extensions)