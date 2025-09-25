# ILockBytes::ReadAt

## Description

The **ReadAt** method reads a specified number of bytes starting at a specified offset from the beginning of the byte array object.

## Parameters

### `ulOffset` [in]

Specifies the starting point from the beginning of the byte array for reading data.

### `pv` [in]

Pointer to the buffer into which the byte array is read. The size of this buffer is contained in *cb*.

### `cb` [in]

Specifies the number of bytes of data to attempt to read from the byte array.

### `pcbRead` [out]

Pointer to a **ULONG** where this method writes the actual number of bytes read from the byte array. You can set this pointer to **NULL** to indicate that you are not interested in this value. In this case, this method does not provide the actual number of bytes that were read.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | Indicates that the specified number of bytes were read, or the maximum number of bytes were read to the end of the byte array.|
|E_FAIL | Data could not be read from the byte array.|
|E_PENDING | Asynchronous Storage only: Part or all of the data to be read is currently unavailable. |
|STG_E_ACCESSDENIED | The caller does not have permission to access the byte array.|
|STG_E_READFAULT | The number of bytes to be read does not equal the number of bytes that were actually read.|

## Remarks

**ILockBytes::ReadAt** reads bytes from the byte array object. It reports the number of bytes that were actually read. This value may be less than the number of bytes requested if an error occurs or if the end of the byte array is reached during the read.

It is not an error to read less than the specified number of bytes if the operation encounters the end of the byte array. Note that this is the same end-of-file behavior as found in MS-DOS file allocation table (FAT) file system files.

## See also

[ILockBytes - File-Based Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-file-based-implementation)

[ILockBytes - Global Memory Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-global-memory-implementation)

[ILockBytes::WriteAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-writeat)