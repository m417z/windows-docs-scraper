# GetVirtualDiskMetadata function

## Description

Retrieves the specified metadata from the virtual disk.

## Parameters

### `VirtualDiskHandle` [in]

Handle to an open virtual disk.

### `Item` [in]

Address of a **GUID** identifying the metadata to retrieve.

### `MetaDataSize` [in, out]

Address of a **ULONG**. On input, the value indicates the size, in bytes, of
the buffer pointed to by the *MetaData* parameter. On output, the value contains size,
in bytes, of the retrieved metadata. If the buffer was too small, the API will fail and return
**ERROR_INSUFFICIENT_BUFFER**, putting the required size in the
**ULONG** and the buffer will contain the start of the metadata.

### `MetaData` [out]

Address of the buffer where the metadata is to be stored.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the buffer pointed to by the *Items* parameter was too small, the return value is
**ERROR_INSUFFICIENT_BUFFER**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[VHD Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323699(v=vs.85))