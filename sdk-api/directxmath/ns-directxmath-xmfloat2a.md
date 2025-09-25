# XMFLOAT2A Structure

## Description

Describes an [XMFLOAT2](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat2) structure aligned on a 16-byte boundary.

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `XMFLOAT2`

An **XMFLOAT2** object.

## Remarks

`XMFLOAT2A` can be loaded into instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using [XMLoadFloat2A](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmloadfloat2a).

Instances of `XMVECTOR` can be stored into an instance of `XMFLOAT2A` with **XMStoreFloat2A**.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMFLOAT2](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat2)