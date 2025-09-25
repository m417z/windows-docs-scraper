# XMUDEC4 structure

## Description

A 4D vector with x-,y-, and z- components represented as 10 bit unsigned integer values, and the
w-component as a 2 bit unsigned integer value.

For a list of additional functionality such as constructors and operators that are available
using `XMUDEC4` when you are programming in C++, see [XMUDEC4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmudec4-extensions).

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

### `XMUDEC4`

TBD

### `operator` uint32_t

TBD

### `operator=`

TBD

## Remarks

`XMUDEC4` can be loaded into instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using
[XMLoadUDec4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadudec4).

Instances of `XMVECTOR` can be stored into an instance of `XMUDEC4` with [XMStoreUDec4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstoreudec4).

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMUDEC4 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmudec4-extensions)