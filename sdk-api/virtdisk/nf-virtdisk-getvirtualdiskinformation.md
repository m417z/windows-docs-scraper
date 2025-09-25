# GetVirtualDiskInformation function

## Description

Retrieves information about a virtual hard disk (VHD).

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open VHD, which must have been opened using the
**VIRTUAL_DISK_ACCESS_GET_INFO** flag set in the
*VirtualDiskAccessMask* parameter to the
[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function. For information on how to
open a VHD, see the **OpenVirtualDisk** function.

### `VirtualDiskInfoSize` [in, out]

A pointer to a **ULONG** that contains the size of the
*VirtualDiskInfo* parameter.

### `VirtualDiskInfo` [in, out]

A pointer to a valid [GET_VIRTUAL_DISK_INFO](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-get_virtual_disk_info)
structure. The format of the data returned is dependent on the value passed in the
**Version** member by the caller.

### `SizeUsed` [in, out, optional]

A pointer to a **ULONG** that contains the size used.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS** and the
*VirtualDiskInfo* parameter contains the requested information.

If the function fails, the return value is an error code and the *VirtualDiskInfo*
parameter is undefined. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **GetVirtualDiskInformation** function
can be called on any valid *VirtualDiskHandle*, provided the handle was opened using the
**VIRTUAL_DISK_ACCESS_GET_INFO** flag. The VHD is not required to be an attached disk.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[GET_VIRTUAL_DISK_INFO](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-get_virtual_disk_info)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))