# XMFLOAT4X3A structure

## Description

Describes an [XMFLOAT4X3](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4x3) structure aligned on a 16-byte boundary.

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `XMFLOAT4X3`

An **XMFLOAT4X3** object.

## Remarks

`XMFLOAT4X3A` can be loaded into instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using [XMLoadFloat4x3A](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmloadfloat4x3a).

Instances of `XMVECTOR` can be stored into an instance of `XMFLOAT4X3A` with [XMStoreFloat4x3A](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmstorefloat4x3a).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMFLOAT4X3](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4x3)