# XMFLOAT3 structure

## Description

Describes a 3D vector consisting of three single-precision floating-point values.

For a list of additional functionality such as constructors and operators that are available using `XMFLOAT3` when you
are programming in C++, see [XMFLOAT3 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmfloat3-extensions).

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information
about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `x`

**float** value describing the x-coordinate of the vector.

### `y`

**float** value describing the y-coordinate of the vector.

### `z`

**float** value describing the z-coordinate of the vector.

### `operator=`

TBD

### `XMFLOAT3`

TBD

## Remarks

`XMFLOAT3` can be loaded into instances of  [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using
[XMLoadFloat3](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmloadfloat3).

Instances of `XMVECTOR` can be stored into an instance of `XMFLOAT3` with
[XMStoreFloat3](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmstorefloat3).

**Namespace:** Use DirectX

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMFLOAT3 Extensions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xmfloat3-extensions)