# ILockBytes::WriteAt

## Description

The **WriteAt** method writes the specified number of bytes starting at a specified offset from the beginning of the byte array.

## Parameters

### `ulOffset` [in]

Specifies the starting point from the beginning of the byte array for the data to be written.

### `pv` [in]

Pointer to the buffer containing the data to be written.

### `cb` [in]

Specifies the number of bytes of data to attempt to write into the byte array.

### `pcbWritten` [out]

Pointer to a location where this method specifies the actual number of bytes written to the byte array. You can set this pointer to **NULL** to indicate that you are not interested in this value. In this case, this method does not provide the actual number of bytes written.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | Indicates that the specified number of bytes were written.|
|E_FAIL | A general failure occurred during the write operation.|
|E_PENDING | Asynchronous Storage only: Part or all of the data to be written is currently unavailable.|
|STG_E_ACCESSDENIED | The caller does not have enough permissions for writing this byte array.|
|STG_E_WRITEFAULT | The number of bytes to be written does not equal the number of bytes that were actually written.|
|STG_E_MEDIUMFULL | The write operation was not completed because there is no space left on the storage device. The actual number of bytes written is still returned in *pcbWritten*.|

## Remarks

**ILockBytes::WriteAt** writes the specified data at the specified location in the byte array. The number of bytes actually written must always be returned in *pcbWritten*, even if an error is returned. If the byte count is zero bytes, the write operation has no effect.

If *ulOffset* is past the end of the byte array and *cb* is greater than zero, **ILockBytes::WriteAt** increases the size of the byte array. The fill bytes written to the byte array are not initialized to any particular value.

## See also

[ILockBytes - File-Based Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-file-based-implementation)

[ILockBytes - Global Memory Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-global-memory-implementation)

[ILockBytes::ReadAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-readat)

[ILockBytes::SetSize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-setsize)