# AttachVirtualDisk function

## Description

Attaches a virtual hard disk (VHD) or CD or DVD image file (ISO) by locating an appropriate VHD
provider to accomplish the attachment.

## Parameters

### `VirtualDiskHandle` [in]

A handle to an open virtual disk. For information on how to open a virtual disk, see the
[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function.

### `SecurityDescriptor` [in, optional]

An optional pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) to apply to the attached
virtual disk. If this parameter is **NULL**, the security descriptor of the virtual disk
image file is used.

Ensure that the security descriptor that **AttachVirtualDisk** applies to the attached virtual disk grants the write attributes permission for the user, or that the security descriptor of the virtual disk
image file grants the write attributes permission for the user if you specify NULL for this parameter. If the security descriptor does not grant write attributes permission for a user, Shell displays the following error when the user accesses the attached virtual disk: **The Recycle Bin is corrupted. Do you want to empty the Recycle Bin for this drive?**

### `Flags` [in]

A valid combination of values of the
[ATTACH_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-attach_virtual_disk_flag) enumeration.

### `ProviderSpecificFlags` [in]

Flags specific to the type of virtual disk being attached. May be zero if none are required.

### `Parameters` [in, optional]

A pointer to a valid
[ATTACH_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-attach_virtual_disk_parameters)
structure that contains attachment parameter data.

### `Overlapped` [in, optional]

An optional pointer to a valid [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)
structure if
[asynchronous](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output) operation is
desired.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **AttachVirtualDisk** function is not supported
for VHDs or ISOs hosted on Secure Digital (SD) media plugged into an SD controller in native mode (for which
sffdisk.sys, sffp_sd.sys, and sdbus.sys drivers would be loaded) and will
fail with the error **ERROR_FILE_NOT_FOUND**. VHDs and ISOs hosted on SD media connected to
a USB reader are supported.

If the **AttachVirtualDisk** function fails with an
error code value of **ERROR_INVALID_PARAMETER**, the cause may be due to any of the
following conditions:

* The *VirtualDiskHandle* parameter is not a valid handle created by the
  [OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function.
* The *Flags* parameter is set to a value larger than
  `0x020`.
* The **Version** member of the *Parameters* parameter is not
  set to **ATTACH_VIRTUAL_DISK_VERSION_1**.

The host volume that contains the virtual disk image file cannot be compressed or EFS encrypted.

This function will fail if a provider cannot be found, if the VHD or ISO image file is not valid, if the VHD
image is already attached, or if the caller does not have **SE_MANAGE_VOLUME_PRIVILEGE**
access rights. For more information about file security, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

The intended access mode of the virtual disk must be considered when opening the virtual disk handle. For
example, if the virtual disk is being attached for read/write access, the
*VirtualDiskHandle* parameter must have been opened using the
**VIRTUAL_DISK_ACCESS_ATTACH_RW** access flag. For more information, see
[VIRTUAL_DISK_ACCESS_MASK](https://learn.microsoft.com/openspecs/windows_protocols/ms-vds/4fa2f54d-00b3-4cd9-b673-a6b8d64ed57f) and
[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk).

CD and DVD image files (ISO) are not supported before Windows 8 and
Windows Server 2012.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))