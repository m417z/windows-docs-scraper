# SetVirtualDiskInformation function

## Description

Sets information about a virtual hard disk (VHD).

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open virtual disk, which must have been opened using the
**VIRTUAL_DISK_ACCESS_METAOPS** flag. For information on how to open a virtual disk, see
the [OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function.

### `VirtualDiskInfo` [in]

A pointer to a valid [SET_VIRTUAL_DISK_INFO](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-set_virtual_disk_info)
structure.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **SetVirtualDiskInformation** function
will fail if the **ParentFilePath** member is requested to be set but the system cannot
resolve the path provided.

Setting the parent information will also cause the child's parent
**GUID** and Timestamp fields to be updated.

The virtual disk cannot be attached while this operation is in progress.

The caller must have READ|WRITE access to the backing store for the virtual disk.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))