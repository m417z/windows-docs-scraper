# ISequentialStream::Read

## Description

The **Read** method reads a specified number of bytes from the stream object into memory, starting at the current seek pointer.

## Parameters

### `pv` [out]

A pointer to the buffer which the stream data is read into.

### `cb` [in]

The number of bytes of data to read from the stream object.

### `pcbRead` [out]

A pointer to a **ULONG** variable that receives the actual number of bytes read from the stream object.

**Note** The number of bytes read may be zero.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | All of the requested data was successfully read from the stream object; the number of bytes requested in *cb* is the same as the number of bytes returned in *pcbRead*.|
|S_FALSE | The value returned in *pcbRead* is less than the number of bytes requested in *cb*. This indicates the end of the stream has been reached. The number of bytes read indicates how much of the *pv* buffer has been filled.|
|E_PENDING | Asynchronous storage only: Part or all of the data to be read is currently unavailable. |
|STG_E_ACCESSDENIED | The caller does not have permissions required to read this stream object.|
|STG_E_INVALIDPOINTER | One of the pointer values is invalid.|
|STG_E_REVERTED | The object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

This method reads bytes from this stream object into memory. The stream object must be opened in **STGM_READ** mode. This method adjusts the seek pointer by the actual number of bytes read.

The number of bytes actually read is also returned in the *pcbRead* parameter.

### Notes to Callers

The actual number of bytes read can be less than the number of bytes requested if an error occurs or if the end of the stream is reached during the read operation. The number of bytes returned should always be compared to the number of bytes requested. If the number of bytes returned is less than the number of bytes requested, it usually means the **Read** method attempted to read past the end of the stream.

The application should handle both a returned error and **S_OK** return values on end-of-stream read operations.

## See also

[ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write)

[IStorage::OpenStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstream)

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)

[STGMOVE](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-stgmove)