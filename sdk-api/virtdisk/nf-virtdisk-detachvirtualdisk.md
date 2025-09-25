# DetachVirtualDisk function

## Description

Detaches a virtual hard disk (VHD) or CD or DVD image file (ISO) by locating an appropriate virtual
disk provider to accomplish the operation.

## Parameters

### `VirtualDiskHandle` [in]

A handle to an open virtual disk, which must have been opened using the
**VIRTUAL_DISK_ACCESS_DETACH** flag set in the
*VirtualDiskAccessMask* parameter to the
[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function. For information on how to
open a virtual disk, see the **OpenVirtualDisk**
function.

### `Flags` [in]

A valid combination of values of the
[DETACH_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-detach_virtual_disk_flag) enumeration.

### `ProviderSpecificFlags` [in]

Flags specific to the type of virtual disk being detached. May be zero if none are required.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

If the **DetachVirtualDisk** function fails with an
error code value of **ERROR_INVALID_PARAMETER**, the cause may be due to any of the
following conditions:

* The *VirtualDiskHandle* parameter is not a valid handle created by the
  [OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function.
* The *Flags* parameter is set to a value other than
  **DETACH_VIRTUAL_DISK_FLAG_NONE** (0).

The host volume that contains the virtual disk image file cannot be compressed or EFS encrypted.

All other open handles to the virtual disk must be closed before the
**DetachVirtualDisk** function can succeed.

If the virtual disk is attached and another handle that was used to attach it has
been closed, this is because the **ATTACH_VIRTUAL_DISK_FLAG_PERMANENT_LIFETIME** flag was
specified. In this case, the **DetachVirtualDisk**
function can succeed but the VHD will remain attached. If the
**ATTACH_VIRTUAL_DISK_FLAG_PERMANENT_LIFETIME** was not specified, the virtual disk will be
automatically detached when the last open handle is closed.

This function will fail if a provider cannot be found, if the image file is not valid, if the image is not
attached, or if the caller does not have **SE_MANAGE_VOLUME_PRIVILEGE** access rights on a
Windows Server operating system. For more information about file security, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

CD and DVD image files (ISO) are not supported before Windows 8 and
Windows Server 2012.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))