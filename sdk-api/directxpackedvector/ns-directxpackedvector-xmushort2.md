# XMUSHORT2 structure

## Description

Describes a 2D vector consisting of 16-bit unsigned integer components.

For a list of additional functionality such as constructors and operators that are available
using `XMUSHORT2` when you are programming in C++, see [XMUSHORT2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmushort2-extensions).

**Note** See [DirectXMath Library Type
Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Unsigned integer in the range [0, 65535] describing the x-coordinate of the
vector.

### `y`

Unsigned integer in the range [0, 65535] describing the y-coordinate of the
vector.

### `v`

### `XMUSHORT2`

TBD

### `operator=`

TBD

## Remarks

`XMUSHORT2` can be loaded into instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using
[XMLoadUShort2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadushort2).

Instances of `XMVECTOR` can be stored into an instance of `XMUSHORT2` with [XMStoreUShort2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreushort2).

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMUSHORT2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmushort2-extensions)