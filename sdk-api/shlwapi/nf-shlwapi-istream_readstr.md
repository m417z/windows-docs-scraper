# IStream_ReadStr function

## Description

Reads from a stream and writes into a string.

## Parameters

### `pstm` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the stream from which to read.

### `ppsz` [out]

Type: **PWSTR***

A pointer to the null-terminated, Unicode string into which the stream is written.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.