# XMBYTE2 structure

## Description

A 2D vector where each component is a signed integer, 8-bits (1 byte) in length.

For a list of additional functionality such as constructors and operators that are available using `XMBYTE2` when you
are programming in C++, see [XMBYTE2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmbyte2-extensions).

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about
equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Signed 8-bit integer value in the range [-127, 127] describing the x-coordinate of the vector.

### `y`

Signed 8-bit integer value in the range [-127, 127] describing the y-coordinate of the vector.

### `v`

### `XMBYTE2`

TBD

### `operator=`

TBD

## Remarks

You can use [XMLoadByte2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadbyte2) to load `XMBYTE2` into instances
of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

You can use [XMStoreByte2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmstorebyte2) to store instances of `XMVECTOR`
into an instance of `XMBYTE2`.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMBYTE2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmbyte2-extensions)