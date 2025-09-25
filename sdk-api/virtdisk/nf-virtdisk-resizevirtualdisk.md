# ResizeVirtualDisk function

## Description

Resizes a virtual disk.

## Parameters

### `VirtualDiskHandle` [in]

Handle to an open virtual disk.

### `Flags` [in]

Zero or more flags enumerated from the
[RESIZE_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/desktop/api/virtdisk/ne-virtdisk-resize_virtual_disk_flag) enumeration.

### `Parameters` [in]

Address of a
[RESIZE_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/virtdisk/ns-virtdisk-resize_virtual_disk_parameters)
structure containing the new size of the virtual disk.

### `Overlapped` [in, optional]

If this is to be an asynchronous operation, the address of a valid
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[RESIZE_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/desktop/api/virtdisk/ne-virtdisk-resize_virtual_disk_flag)

[RESIZE_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/virtdisk/ns-virtdisk-resize_virtual_disk_parameters)

[VHD Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323699(v=vs.85))