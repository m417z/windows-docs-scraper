# IStream::SetSize

## Description

The **SetSize** method changes the size of the stream object.

## Parameters

### `libNewSize` [in]

Specifies the new size, in bytes, of the stream.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The size of the stream object was successfully changed.|
|E_PENDING | Asynchronous Storage only: Part or all of the stream's data is currently unavailable.|
|STG_E_MEDIUMFULL | The stream size is not changed because there is no space left on the storage device.|
|STG_E_INVALIDFUNCTION | The value of the *libNewSize* parameter is not supported by the implementation. Not all streams support greater than 232 bytes. If a stream does not support more than 232 bytes, the high DWORD data type of *libNewSize* must be zero. If it is nonzero, the implementation may return STG_E_INVALIDFUNCTION. In general, COM-based implementations of the IStream interface do not support streams larger than 232 bytes.|
|STG_E_REVERTED | The object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

**IStream::SetSize** changes the size of the stream object. Call this method to preallocate space for the stream. If the *libNewSize* parameter is larger than the current stream size, the stream is extended to the indicated size by filling the intervening space with bytes of undefined value. This operation is similar to the
[ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) method if the seek pointer is past the current end of the stream.

If the *libNewSize* parameter is smaller than the current stream, the stream is truncated to the indicated size.

The seek pointer is not affected by the change in stream size.

Calling **IStream::SetSize** can be an effective way to obtain a large chunk of contiguous space.

## See also

[ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write)

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)