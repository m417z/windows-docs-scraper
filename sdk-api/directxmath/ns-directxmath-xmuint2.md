# XMUINT2 structure

## Description

A 2D vector where each component is an unsigned integer.

For a list of additional functionality such as constructors and operators that are available using `XMUINT2` when you
are programming in C++, see [XMUINT2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmuint2-extensions).

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about
equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Unsigned integer value describing the x-coordinate of the vector.

### `y`

Unsigned integer value describing the y-coordinate of the vector.

### `operator=`

TBD

### `XMUINT2`

TBD

## Remarks

You can use [XMLoadUInt2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmloaduint2) to load `XMUINT2` into instances
of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

You can use [XMStoreUInt2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmstoreuint2) to store instances of `XMVECTOR`
into an instance of `XMUINT2`.

**Namespace:** Use DirectX

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMUINT2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmuint2-extensions)