# XMCOLOR structure

## Description

A 32-bit Alpha Red Green Blue (ARGB) color vector, where each color channel is specified as
an unsigned 8 bit integer.

For a list of additional functionality such as constructors and operators that are available
using `XMCOLOR` when you are programming in C++, see [XMCOLOR Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmcolor-extensions).

**Note** See [DirectXMath Library Type
Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype),
[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat),and [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `b`

Unsigned integer between 0 and 255 representing the blue component.

### `g`

Unsigned integer between 0 and 255 representing the green component.

### `r`

Unsigned integer between 0 and 255 representing the red component.

### `a`

Unsigned integer between 0 and 255 representing the alpha component.

### `c`

Unsigned 32-bit integer representing the color. The colors are stored in A8R8G8B8 format.

The alpha component the most-significant bits, and the blue component is
stored in the least-significant bits.

### `XMCOLOR`

TBD

### `operator` uint32_t

TBD

### `operator=`

TBD

## Remarks

Those `XMCOLOR` constructors using floating point arguments require normalized input, which
are clamped to the range of [0-1.0]. During instantiation, the floating point data
specifying the color channels are multiplied by 255.0f, rounded and then assigned to the
appropriate members of `XMCOLOR`.

`XMCOLOR` can be used to load instances of  [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) from
normalized values, by using [XMLoadColor](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadcolor), which divides color channel
data by 255.0f, rounds the result, and then assigns the components to an `XMVECTOR` instance.

`XMVECTOR` instances containing normalized values can be stored into `XMCOLOR` using [XMStoreColor](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstorecolor), which multiplies color channel data by 255.0f,
rounding the result before assigning the values to the appropriate `XMCOLOR` members.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMCOLOR Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmcolor-extensions)