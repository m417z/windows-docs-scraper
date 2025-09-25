# GetVirtualDiskPhysicalPath function

## Description

Retrieves the path to the physical device object that contains a virtual hard disk
(VHD) or CD or DVD image file (ISO).

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open virtual disk, which must have been opened using the
**VIRTUAL_DISK_ACCESS_GET_INFO** flag. For information on how to open a virtual disk, see
the [OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function.

### `DiskPathSizeInBytes` [in, out]

The size, in bytes, of the buffer pointed to by the *DiskPath* parameter.

### `DiskPath` [out, optional]

A target buffer to receive the path of the physical disk device that contains the virtual disk.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS** and the
*DiskPath* parameter contains a pointer to a populated string.

If the function fails, the return value is an error code and the value of the contents of the buffer referred
to by the *DiskPath* parameter is undefined. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

For the **GetVirtualDiskPhysicalPath**
function to succeed, the virtual disk referred to by the *VirtualDiskHandle* parameter
must be attached, the physical disk object must be to be located by the system, and the
*DiskPath* parameter must refer to a buffer large enough to hold the resulting path. This
path is in the form \\.\*PhysicalDriveX* where *X*
is an integer that represents the particular enumeration of the physical disk on the caller's system.

CD and DVD image files (ISO) are not supported before Windows 8 and
Windows Server 2012.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))