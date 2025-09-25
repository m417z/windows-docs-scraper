# XMUBYTEN2 structure

## Description

A 2D vector for storing unsigned, normalized values as signed 8-bits (1 byte) integers.

For a list of additional functionality such as constructors and operators that are available using `XMUBYTEN2` when you
are programming in C++, see [XMUBYTEN2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmubyten2-extensions).

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about
equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Unsigned 8-bit integer value in the range [0, 255] describing the x-coordinate of the vector.

### `y`

Unsigned 8-bit integer value in the range [0, 255] describing the y-coordinate of the vector.

### `v`

### `XMUBYTEN2`

TBD

### `operator=`

TBD

## Remarks

Those `XMUBYTEN2` constructors using floating point arguments require normalized input, which must be in the range of
[0.0.-1.0]. During instantiation, this data is multiplied by 255.0f, results are rounded, and then assigned to the
appropriate members of `XMUBYTEN2`.

`XMUBYTEN2` can be used to load instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) from normalized values, by using
[XMLoadUByteN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadubyten2), which divides each component 255.0f, rounds the result, and then assigns the
components to an `XMVECTOR` instance.

`XMVECTOR` instances containing normalized values can be stored into `XMUBYTEN2` using
[XMStoreUByteN2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreubyten2), which multiplies each component by 255.0f, rounding the result, before assigning
the values to the appropriate `XMUBYTEN2` members.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMUBYTEN2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmubyten2-extensions)