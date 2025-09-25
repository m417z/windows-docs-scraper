# ExpandVirtualDisk function

## Description

Increases the size of a fixed or dynamically expandable virtual hard disk (VHD).

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open virtual disk, which must have been opened using the **VIRTUAL_DISK_ACCESS_METAOPS** flag. For information on how to open a virtual disk, see the [OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function.

### `Flags` [in]

Must be the **EXPAND_VIRTUAL_DISK_FLAG_NONE** value of the [EXPAND_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-expand_virtual_disk_flag) enumeration.

### `Parameters` [in]

A pointer to a valid [EXPAND_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-expand_virtual_disk_parameters) structure that contains expansion parameter data.

### `Overlapped` [in, optional]

An optional pointer to a valid [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure if [asynchronous](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output) operation is desired.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **ExpandVirtualDisk** function performs the operation in-place, and therefore does not create a virtual disk.

The expand operation is valid only for fixed and expandable virtual disks and will invalidate a differencing virtual disk chain.

Expanding a virtual disk requires that the virtual disk be detached during the operation.

The caller must have READ|WRITE access to the backing store for the virtual disk.

For an expandable virtual disk, the **ExpandVirtualDisk** function may not result in a larger file because the size is virtual and would not actually grow physically until used.

If the virtual disk is expandable and the host volume does not have enough space for the new size, the **ExpandVirtualDisk** function can succeed anyway. Future writes to the virtual disk may fail if the host volume runs out of space as the virtual disk expands.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))