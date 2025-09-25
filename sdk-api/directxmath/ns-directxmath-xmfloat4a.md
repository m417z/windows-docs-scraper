# XMFLOAT4A structure

## Description

Describes an [XMFLOAT4](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4) structure aligned on a 16-byte boundary.

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `XMFLOAT4`

An **XMFLOAT4** object.

## Remarks

`XMFLOAT4A` can be loaded into instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using [XMLoadFloat4A](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmloadfloat4a).

Instances of `XMVECTOR` can be stored into an instance of `XMFLOAT4A` with [XMStoreFloat4A](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmstorefloat4a).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMFLOAT4](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4)