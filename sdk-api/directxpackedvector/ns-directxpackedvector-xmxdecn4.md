# XMXDECN4 structure

## Description

A 4D vector for storing signed, normalized values as 10 bit signed x-,y-, and z- components
and an unsigned, normalized value as 2 bit unsigned w-component.

For a list of additional functionality such as constructors and operators that are available
using `XMXDECN4` when you are programming in C++, see [XMXDECN4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmxdecn4-extensions).

**Note** See [DirectXMath Library Type
Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Signed integer value in the range [-511, 511] describing the
x-coordinate of the vector.

### `y`

Signed integer value in the range [-511, 511] describing the
y-coordinate of the vector.

### `z`

Signed integer value in the range [-511, 511] describing the
z-coordinate of the vector.

### `w`

Unsigned integer value in the range [0, 3] describing the w-coordinate
of the vector.

### `v`

Unsigned 32-bit integer representing the 4D vector.

### `XMXDECN4`

TBD

### `operator` uint32_t

TBD

### `operator=`

TBD

## Remarks

Those `XMXDECN4` constructors using floating point arguments require normalized input,
which must be in the range of [-1.0.-1.0] for x-, y-, z-components and 0.0 for
the w-component. During instantiation, the inputs specifying the x-, y-, and
z-components are multiplied by 511.0f and the w-component by 3.0f, these results are
rounded and then assigned to the appropriate members of `XMXDECN4`.

`XMXDECN4` can be used to load instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) from normalized
values, by using [XMLoadXDecN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadxdecn4), which divides the x-, y-, and
z-components by 511.0f, the w-component by 3.0f, rounds the result, and then assigns
the components to an `XMVECTOR` instance.

`XMVECTOR` instances containing normalized values can be stored into `XMXDECN4` using [XMStoreXDecN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstorexdecn4), which multiplies the x-, y-,and z-components by
511.0f, the w-component by 3.0f, rounding the result, before assigning the values to the
appropriate `XMXDECN4` members.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMXDECN4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmxdecn4-extensions)