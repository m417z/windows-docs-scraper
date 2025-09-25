# IStream_Copy function

## Description

Copies a stream to another stream.

## Parameters

### `pstmFrom` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the source stream.

### `pstmTo` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the destination stream.

### `cb` [in]

Type: **DWORD**

The number of bytes to copy from the source stream.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.