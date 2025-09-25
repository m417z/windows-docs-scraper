# AddVirtualDiskParent function

## Description

Attaches a parent to a virtual disk opened with the
**OPEN_VIRTUAL_DISK_FLAG_CUSTOM_DIFF_CHAIN** flag.

## Parameters

### `VirtualDiskHandle` [in]

Handle to a virtual disk.

### `ParentPath` [in]

Address of a string containing a valid path to the virtual hard disk image to add as a parent.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This adds the specified parent virtual hard disk to the head of the differencing chain of the specified
virtual hard disk. If the differencing chain extends beyond the parent, this function can be called repeatedly to
add additional parents to the differencing chain.

## See also

[VHD Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323699(v=vs.85))