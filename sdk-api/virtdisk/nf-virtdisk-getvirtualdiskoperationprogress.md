# GetVirtualDiskOperationProgress function

## Description

Checks the progress of an asynchronous virtual hard disk (VHD) operation.

## Parameters

### `VirtualDiskHandle` [in]

A valid handle to a virtual disk with a pending asynchronous operation.

### `Overlapped` [in]

A pointer to a valid [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. This
parameter must reference the same structure previously sent to the virtual disk operation being checked for
progress.

### `Progress` [out]

A pointer to a [VIRTUAL_DISK_PROGRESS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-virtual_disk_progress)
structure that receives the current virtual disk operation progress.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS** and the
*Progress* parameter will be populated with the current virtual disk operation
progress.

If the function fails, the return value is an error code and the value of the
*Progress* parameter is undefined. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))

[VIRTUAL_DISK_PROGRESS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-virtual_disk_progress)