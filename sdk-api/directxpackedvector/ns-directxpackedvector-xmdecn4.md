# XMDECN4 structure

## Description

A 4D vector for storing signed, normalized values as 10 bit signed x-,y-, and z- components
and a 2 bit signed w-component.

For a list of additional functionality such as constructors and operators that are available
using `XMDECN4` when you are programming in C++, see [XMDECN4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmdecn4-extensions).

**Note** See [DirectXMath Library Type
Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat),and [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

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

Signed integer value in the range [-1, 1] describing the
w-coordinate of the vector.

### `v`

Unsigned 32-bit integer representing the 4D vector.

### `XMDECN4`

TBD

### `operator` uint32_t

TBD

### `operator=`

TBD

## Remarks

Those `XMDECN4` constructors using floating point arguments require normalized input,
which must be in the range of [-1.0.-1.0]. During instantiation, the inputs
specifying the x-, y-, and z-components are then multiplied by 511.0f, the results are
rounded and then assigned to the appropriate members of `XMDECN4`.

`XMDECN4` can be used to load instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) from
normalized values, by using [XMLoadDecN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloaddecn4), which divides the x-, y-, and
z-components by 511.0f, rounds the result, and then assigns the components to
an `XMVECTOR` instance.

`XMVECTOR` instances containing normalized values can be stored into `XMDECN4` using [XMStoreDecN4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoredecn4), which multiplies the x-, y-,and z-components by
511.0f , rounding the result, before assigning the values to the appropriate `XMDECN4` members.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMDECN4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmdecn4-extensions)