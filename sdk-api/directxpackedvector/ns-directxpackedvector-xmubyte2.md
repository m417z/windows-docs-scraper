# XMUBYTE2 structure

## Description

Describes a 2D vector where each component is a unsigned integer, 8-bits (1 byte) in length.

A 2D vector where each component is a unsigned integer, 8-bits (1 byte) in length.

For a list of additional functionality such as constructors and operators that are available using `XMUBYTE2` when you
are programming in C++, see [XMUBYTE2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmubyte2-extensions).

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about
equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Unsigned 8-bit integer value in the range [0, 255] describing the x-coordinate of the vector.

### `y`

Unsigned 8-bit integer value in the range [0, 255] describing the y-coordinate of the vector.

### `v`

### `XMUBYTE2`

TBD

### `operator=`

TBD

## Remarks

You can use [XMLoadUByte2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadubyte2) to load `XMUBYTE2`
into instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

You can use [XMStoreUByte2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreubyte2) to store instances of `XMVECTOR`
into an instance of `XMUBYTE2`.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMUBYTE2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmubyte2-extensions)