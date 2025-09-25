# IStream_Write function

## Description

Writes data of unknown format from a buffer to a specified stream.

## Parameters

### `pstm` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer that specifies the target stream.

### `pv` [in]

Type: **const void***

Pointer to a buffer that holds the data to send to the target stream. This buffer must be at least *cb* bytes in size.

### `cb` [in]

Type: **ULONG**

The number of bytes of data to write to the target stream.

## Return value

Type: **HRESULT**

Returns S_OK if the function successfully wrote the specified number of bytes to the stream, or an error value otherwise. In particular, if less than *cb* bytes was written to the target stream, even if some data was successfully written, the function returns E_FAIL.