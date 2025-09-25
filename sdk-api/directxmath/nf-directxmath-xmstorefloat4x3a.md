# XMStoreFloat4x3A function

## Description

Stores an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) in an [XMFLOAT4X3A](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee419612(v=vs.85)).

## Parameters

### `pDestination` [out]

Address at which to store the data. This address must be 16-byte aligned.

### `M` [in]

Matrix containing the data to store.

## Return value

None.

## Remarks

[XMFLOAT4X3A](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee419612(v=vs.85)) is a row-major matrix form. This function cannot be used
to write out column-major data since it assumes the last column is

```
assert(pDestination);
assert(((uint32_t_PTR)pDestination & 0xF) == 0);

pDestination->m[0][0] = M.r[0].v[0];
pDestination->m[0][1] = M.r[0].v[1];
pDestination->m[0][2] = M.r[0].v[2];

pDestination->m[1][0] = M.r[1].v[0];
pDestination->m[1][1] = M.r[1].v[1];
pDestination->m[1][2] = M.r[1].v[2];

pDestination->m[2][0] = M.r[2].v[0];
pDestination->m[2][1] = M.r[2].v[1];
pDestination->m[2][2] = M.r[2].v[2];

pDestination->m[3][0] = M.r[3].v[0];
pDestination->m[3][1] = M.r[3].v[1];
pDestination->m[3][2] = M.r[3].v[2];
```

.

The following pseudocode demonstrates the operation of the function.

`0 0 0 1`

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Store Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-storage)