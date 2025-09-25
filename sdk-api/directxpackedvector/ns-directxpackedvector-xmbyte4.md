# XMBYTE4 structure

## Description

A 4D vector where each component is a signed integer, 8-bits (1 byte) in length.

For a list of additional functionality such as constructors and operators that are available
using `XMBYTE4` when you are programming in C++, see [XMBYTE4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmbyte4-extensions).

**Note** See [DirectXMath Library Type
Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Signed 8-bit integer value in the range [-127, 127] describing the
x-coordinate of the vector.

### `y`

Signed 8-bit integer value in the range [-127, 127] describing the
y-coordinate of the vector.

### `z`

Signed 8-bit integer value in the range [-127, 127] describing the
z-coordinate of the vector.

### `w`

Signed 8-bit integer value in the range [-127, 127] describing the
w-coordinate of the vector.

### `v`

Unsigned 32-bit integer representing the 4D vector.

### `XMBYTE4`

TBD

### `operator=`

TBD

## Remarks

`XMBYTE4` can be loaded into instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using
[XMLoadByte4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadbyte4).

Instances of `XMVECTOR` can be stored into an instance of `XMBYTE4` with [XMStoreByte4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstorebyte4).

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMBYTE4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmbyte4-extensions)