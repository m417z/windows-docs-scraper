# XMINT2 structure

## Description

A 2D vector where each component is a signed integer.

For a list of more functionality such as constructors and operators that are available using `XMINT2` when you
are programming in C++, see [XMINT2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmint2-extensions).

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about
equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

Signed integer value describing the x coordinate of the vector.

### `y`

Signed integer value describing the y coordinate of the vector.

### `operator=`

TBD

### `XMINT2`

TBD

## Remarks

You can use [XMLoadSInt2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmloadsint2) to load `XMINT2` into instances
of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

You can use [XMStoreSInt2](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmstoresint2) to store instances of `XMVECTOR`
into an instance of `XMINT2`.

**Namespace:** Use DirectX

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMINT2 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmint2-extensions)