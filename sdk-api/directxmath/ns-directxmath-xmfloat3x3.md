## Description

A 3x3 floating-point matrix.

> [!NOTE]
> See [Library internals](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-internals) for info about equivalent [D3DDECLTYPE](https://learn.microsoft.com/windows/win32/direct3d9/d3ddecltype), [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat), and [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) objects.

## Members

### `_11`

An element of the matrix.

### `_12`

An element of the matrix.

### `_13`

An element of the matrix.

### `_21`

An element of the matrix.

### `_22`

An element of the matrix.

### `_23`

An element of the matrix.

### `_31`

An element of the matrix.

### `_32`

An element of the matrix.

### `_33`

An element of the matrix.

### `m`

A 2-dimensional 3x3 array representing the matrix.

## Remarks

The scalar members of **XMFLOAT3X3** have names that follow the form *_\<row_number\>\<column_number\>* (for example, *_11*). They provide 1-based indexing, where *row_number* specifies the 1-based matrix row (ranging from 1 to 3), and *column_number* specifies the 1-based matrix column (ranging from 1 to 3).

The member *m* is a 2-dimensional 3x3 array. It provides 0-based indexing of the structure's matrix. When accessing *m\[\<row_index\>, \<column_index\>\]*, *\<row_index\>* ranges from 0 to 2, and *\<column_index\>* ranges from 0 to 2.

You can load an [XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix) from an **XMFLOAT3X3** by using [XMLoadFloat3x3](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmloadfloat3x3).

You can store an [XMMATRIX](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmmatrix) into an **XMFLOAT3X3** by using [XMStoreFloat3x3](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmstorefloat3x3).

## See also

[DirectXMath Library structures](https://learn.microsoft.com/windows/win32/dxmath/ovw-xnamath-reference-structures)