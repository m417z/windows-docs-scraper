# IStream_Read function

## Description

Reads bytes from a specified stream and returns a value that indicates whether all bytes were successfully read.

## Parameters

### `pstm` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface of the stream from which to read.

### `pv` [out]

Type: **VOID***

A pointer to a buffer to receive the stream data from *pstm*. This buffer must be at least *cb* bytes in size.

### `cb` [in]

Type: **ULONG**

The number of bytes of data that the function should attempt to read from the input stream.

## Return value

Type: **HRESULT**

Returns **S_OK** if the function successfully reads the specified number of bytes from the stream, or a COM failure code otherwise. In particular, if the read attempt was successful but fewer than *cb* bytes were read, the function returns **E_FAIL**.

## Remarks

This function calls the [ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) method to read data from the specified stream into the buffer. If the function fails for any reason, the contents of the output buffer and the position of the read pointer in the input stream are undefined.

## See also

[ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read)