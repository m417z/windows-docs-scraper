# SetVirtualDiskMetadata function

## Description

Sets a metadata item for a virtual disk.

## Parameters

### `VirtualDiskHandle` [in]

Handle to an open virtual disk.

### `Item` [in]

Address of a **GUID** identifying the metadata to set. This cannot be the NULL GUID (a GUID of all zeroes).

### `MetaDataSize` [in]

Address of a **ULONG** containing the size, in bytes, of
the buffer pointed to by the *MetaData* parameter.
Specific VHD file types have a maximum size per metadata element. Specific VHD files also have a maximum number of total metadata entries and total metadata size.

### `MetaData` [in]

Address of the buffer containing the metadata to be stored.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[VHD Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323699(v=vs.85))