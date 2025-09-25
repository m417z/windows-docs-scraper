# XMFLOAT4X4A Structure

## Description

Describes an [XMFLOAT4X4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x4) structure aligned on a 16-byte boundary.

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `XMFLOAT4X4`

An **XMFLOAT4X4** object.

## Remarks

`XMFLOAT4X4A` can be loaded into instances of [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using **XMLoadFloat4x4A**.

Instances of `XMVECTOR` can be stored into an instance of `XMFLOAT4X4A` with **XMStoreFloat4x4A**.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMFLOAT4X4](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmfloat4x4)