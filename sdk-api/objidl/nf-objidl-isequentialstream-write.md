# ISequentialStream::Write

## Description

The **Write** method writes a specified number of bytes into the stream object starting at the current seek pointer.

## Parameters

### `pv` [in]

A pointer to the buffer that contains the data that is to be written to the stream. A valid pointer must be provided for this parameter even when *cb* is zero.

### `cb` [in]

The number of bytes of data to attempt to write into the stream. This value can be zero.

### `pcbWritten` [out]

A pointer to a **ULONG** variable where this method writes the actual number of bytes written to the stream object. The caller can set this pointer to **NULL**, in which case this method does not provide the actual number of bytes written.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The data was successfully written to the stream object.|
|E_PENDING | Asynchronous Storage only: Part or all of the data to be written is currently unavailable.|
|STG_E_MEDIUMFULL | The write operation failed because there is no space left on the storage device.|
|STG_E_ACCESSDENIED | The caller does not have the required permissions for writing to this stream object.|
|STG_E_CANTSAVE | Data cannot be written for reasons other than improper access or insufficient space.|
|STG_E_INVALIDPOINTER | One of the pointer values is not valid. The *pv* parameter must contain a valid pointer even if *cb* is zero.|
|STG_E_REVERTED | The object has been invalidated by a revert operation above it in the transaction tree.|
|STG_E_WRITEFAULT | The write operation failed due to a disk error. This value is also returned when this method attempts to write to a stream that was opened in simple mode (using the STGM_SIMPLE flag).|

## Remarks

**ISequentialStream::Write** writes the specified data to a stream object. The seek pointer is adjusted for the number of bytes actually written. The number of bytes actually written is returned in the *pcbWritten* parameter. If the byte count is zero bytes, the write operation has no effect.

If the seek pointer is currently past the end of the stream and the byte count is nonzero, this method increases the size of the stream to the seek pointer and writes the specified bytes starting at the seek pointer. The fill bytes written to the stream are not initialized to any particular value. This is the same as the end-of-file behavior in the MS-DOS FAT file system.

With a zero byte count and a seek pointer past the end of the stream, this method does not create the fill bytes to increase the stream to the seek pointer. In this case, you must call the
[IStream::SetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-setsize) method to increase the size of the stream and write the fill bytes.

The *pcbWritten* parameter can have a value even if an error occurs.

In the COM-provided implementation, stream objects are not sparse. Any fill bytes are eventually allocated on the disk and assigned to the stream.

## See also

[ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read)

[IStorage::OpenStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstream)

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)

[STGMOVE](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-stgmove)