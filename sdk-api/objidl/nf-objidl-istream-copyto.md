# IStream::CopyTo

## Description

The **CopyTo** method copies a specified number of bytes from the current seek pointer in the stream to the current seek pointer in another stream.

## Parameters

### `pstm` [in]

A pointer to the destination stream. The stream pointed to by *pstm* can be a new stream or a clone of the source stream.

### `cb` [in]

The number of bytes to copy from the source stream.

### `pcbRead` [out]

A pointer to the location where this method writes the actual number of bytes read from the source. You can set this pointer to **NULL**. In this case, this method does not provide the actual number of bytes read.

### `pcbWritten` [out]

A pointer to the location where this method writes the actual number of bytes written to the destination. You can set this pointer to **NULL**. In this case, this method does not provide the actual number of bytes written.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The stream object was successfully copied.|
|E_PENDING | Asynchronous Storage only: Part or all of the data to be copied is currently unavailable. |
|STG_E_INVALIDPOINTER | The value of one of the pointer parameters is invalid.|
|STG_E_MEDIUMFULL | The stream is not copied because there is no space left on the storage device.|
|STG_E_REVERTED | The object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

The **CopyTo** method copies the specified bytes from one stream to another. It can also be used to copy a stream to itself. The seek pointer in each stream instance is adjusted for the number of bytes read or written. This method is equivalent to reading *cb* bytes into memory using
[ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) and then immediately writing them to the destination stream using
[ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write), although **IStream::CopyTo** will be more efficient.

The destination stream can be a clone of the source stream created by calling the
[IStream::Clone](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-clone) method.

If **IStream::CopyTo** returns an error, you cannot assume that the seek pointers are valid for either the source or destination. Additionally, the values of *pcbRead* and *pcbWritten* are not meaningful even though they are returned.

If **IStream::CopyTo** returns successfully, the actual number of bytes read and written are the same.

To copy the remainder of the source from the current seek pointer, specify the maximum large integer value for the *cb* parameter. If the seek pointer is the beginning of the stream, this operation copies the entire stream.

## See also

[ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read)

[ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write)

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)

[IStream::Clone](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-clone)