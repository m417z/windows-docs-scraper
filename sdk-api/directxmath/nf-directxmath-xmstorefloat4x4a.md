# XMStoreFloat4x4A function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMFLOAT4X4A](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4x4a).

## Parameters

### `pDestination` [out]

Address at which to store the data. This address must be 16-byte aligned.

### `M` [in]

Matrix containing the data to store.

## Return value

None.

## Remarks

[XMFLOAT4X4A](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat4x4a) is a row-major matrix form. To write out column-major data requires the XMMATRIX be transposed
via [XMMatrixTranpose](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmmatrixtranspose) before calling the store function.

The following pseudocode demonstrates the operation of the function.

```
assert(pDestination);
assert(((uint32_t_PTR)pDestination & 0xF) == 0);

pDestination->m[0][0] = M.r[0].v[0];
pDestination->m[0][1] = M.r[0].v[1];
pDestination->m[0][2] = M.r[0].v[2];
pDestination->m[0][3] = M.r[0].v[3];

pDestination->m[1][0] = M.r[1].v[0];
pDestination->m[1][1] = M.r[1].v[1];
pDestination->m[1][2] = M.r[1].v[2];
pDestination->m[1][3] = M.r[1].v[3];

pDestination->m[2][0] = M.r[2].v[0];
pDestination->m[2][1] = M.r[2].v[1];
pDestination->m[2][2] = M.r[2].v[2];
pDestination->m[2][3] = M.r[2].v[3];

pDestination->m[3][0] = M.r[3].v[0];
pDestination->m[3][1] = M.r[3].v[1];
pDestination->m[3][2] = M.r[3].v[2];
pDestination->m[3][3] = M.r[3].v[3];
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)