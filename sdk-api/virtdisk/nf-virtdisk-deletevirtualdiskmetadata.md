# DeleteVirtualDiskMetadata function

## Description

Deletes metadata from a virtual disk.

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open virtual disk.

### `Item` [in]

The item to be deleted.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[VHD Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323699(v=vs.85))