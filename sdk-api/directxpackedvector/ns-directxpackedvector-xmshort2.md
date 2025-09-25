# XMSHORT2 structure

## Description

Describes a 2D vector consisting of 16-bit signed and normalized integer components.

For a list of additional functionality such as constructors and operators that are available
using `XMSHORT2` when you are programming in C++, see [XMSHORT2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmshort2-extensions).

**Note** See [DirectXMath Library Type
Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Signed integer in the range [-32767, 32767] describing the x-coordinate
of the vector.

### `y`

Signed integer in the range [-32767, 32767] describing the y-coordinate
of the vector.

### `v`

### `XMSHORT2`

TBD

### `operator=`

TBD

## Remarks

The components are normalized when this structure is loaded into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) using [XMLoadShort2](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmloadshort2). Each component will be divided by 32767.0f.

**Namespace:** Use DirectX::PackedVector

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMSHORT2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmshort2-extensions)