# IStream::Seek

## Description

The **Seek** method changes the seek pointer to a new location. The new location is relative to either the beginning of the stream, the end of the stream, or the current seek pointer.

## Parameters

### `dlibMove` [in]

The displacement to be added to the location indicated by the *dwOrigin* parameter. If *dwOrigin* is **STREAM_SEEK_SET**, this is interpreted as an unsigned value rather than a signed value.

### `dwOrigin` [in]

The origin for the displacement specified in *dlibMove*. The origin can be the beginning of the file (**STREAM_SEEK_SET**), the current seek pointer (**STREAM_SEEK_CUR**), or the end of the file (**STREAM_SEEK_END**). For more information about values, see the [STREAM_SEEK](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-stream_seek) enumeration.

### `plibNewPosition` [out]

A pointer to the location where this method writes the value of the new seek pointer from the beginning of the stream.

You can set this pointer to **NULL**. In this case, this method does not provide the new seek pointer.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The seek pointer was successfully adjusted.|
|E_PENDING | Asynchronous Storage only: Part or all of the stream data is currently unavailable. |
|STG_E_INVALIDPOINTER | Indicates that *plibNewPosition* points to invalid memory, because *plibNewPosition* is not read.|
|STG_E_INVALIDFUNCTION | The *dwOrigin* parameter contains an invalid value, or the *dlibMove* parameter contains a bad offset value. For example, the result of the seek pointer is a negative offset value.|
|STG_E_REVERTED | The object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

**IStream::Seek** changes the seek pointer so that subsequent read and write operations can be performed at a different location in the stream object. It is an error to seek before the beginning of the stream. It is not, however, an error to seek past the end of the stream. Seeking past the end of the stream is useful for subsequent write operations, as the stream byte range will be extended to the new seek position immediately before the write is complete.

You can also use this method to obtain the current value of the seek pointer by calling this method with the *dwOrigin* parameter set to **STREAM_SEEK_CUR** and the *dlibMove* parameter set to 0 so that the seek pointer is not changed. The current seek pointer is returned in the *plibNewPosition* parameter.

## See also

[ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read)

[ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write)

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)

[STREAM_SEEK](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-stream_seek)