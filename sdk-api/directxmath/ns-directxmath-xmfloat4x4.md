# XMFLOAT4X4 structure

## Description

A 4*4 floating point matrix.

For a list of additional functionality such as constructors and operators that are available using `XMFLOAT4X4` when you
are programming in C++, see [XMFLOAT4X4 Extensions](https://learn.microsoft.com/windows/win32/dxmath/ovw-xmfloat4x4-extensions).

**Note** See [DirectXMath Library Type Equivalences](https://learn.microsoft.com/windows/desktop/dxmath/pg-xnamath-internals) for information about
equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat), and
[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) objects. objects.

## Members

### `_11`

An element of the matrix.

### `_12`

An element of the matrix.

### `_13`

An element of the matrix.

### `_14`

An element of the matrix.

### `_21`

An element of the matrix.

### `_22`

An element of the matrix.

### `_23`

An element of the matrix.

### `_24`

An element of the matrix.

### `_31`

An element of the matrix.

### `_32`

An element of the matrix.

### `_33`

An element of the matrix.

### `_34`

An element of the matrix.

### `_41`

An element of the matrix.

### `_42`

An element of the matrix.

### `_43`

An element of the matrix.

### `_44`

An element of the matrix.

### `m`

A 4*4 array representing the matrix.

### `operator=`

TBD

### `XMFLOAT4X4`

TBD

### `operator()`

TBD

## Remarks

Scalar members of `XMFLOAT4X4` are of the form **_***RowCol*, and provide one based indexing,
where *Row* specifies the one's based matrix row (running from 1 to 4), and
*Col* specifies the one's based matrix column (running from 1 to 4).

The two dimensional 4*4 array member of `XMFLOAT4X4`, **m**, provides zero based indexing of the structure's
matrix. When accessing `XMFLOAT4X4`**m[***Row***,***Col***]**, *Row* can run from 0 to 3 and *Col* can run from 0 to 3.

`XMFLOAT4X4` can be loaded into instances of  [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by using
[XMLoadFloat4x4](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmloadfloat4x4).

Instances of `XMVECTOR` can be stored into an instance of `XMFLOAT4X4` with
[XMStoreFloat4x4](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmstorefloat4x4).

**Namespace:** Use DirectX

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Structures](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-structures)

[XMFLOAT4X4 Extensions](https://learn.microsoft.com/windows/win32/dxmath/ovw-xmfloat4x4-extensions)

[XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix)