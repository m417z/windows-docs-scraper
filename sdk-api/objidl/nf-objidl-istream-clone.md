# IStream::Clone

## Description

The **Clone** method creates a new stream object with its own seek pointer that references the same bytes as the original stream.

## Parameters

### `ppstm` [out]

When successful, pointer to the location of an
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer to the new stream object. If an error occurs, this parameter is **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The stream was successfully cloned.|
|E_PENDING | Asynchronous Storage only: Part or all of the stream's data is currently unavailable. |
|STG_E_INSUFFICIENTMEMORY | The stream was not cloned due to a lack of memory.|
|STG_E_INVALIDPOINTER | The ppStm pointer is not valid.|
|STG_E_REVERTED | The object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

The **Clone** method creates a new stream object for accessing the same bytes but using a separate seek pointer. The new stream object sees the same data as the source-stream object. Changes written to one object are immediately visible in the other. Range locking is shared between the stream objects.

The initial setting of the seek pointer in the cloned stream instance is the same as the current setting of the seek pointer in the original stream at the time of the clone operation.

## See also

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)

[IStream::CopyTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-copyto)