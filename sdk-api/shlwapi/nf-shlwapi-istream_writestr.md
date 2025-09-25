# IStream_WriteStr function

## Description

Reads from a string and writes into a stream.

## Parameters

### `pstm` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the stream in which to write.

### `psz` [in]

Type: **PCWSTR**

A pointer to a null-terminated, Unicode string from which to read.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.