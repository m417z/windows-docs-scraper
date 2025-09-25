# OpenVirtualDisk function

## Description

Opens a virtual hard disk (VHD) or CD or DVD image file (ISO) for use.

## Parameters

### `VirtualStorageType` [in]

A pointer to a valid [VIRTUAL_STORAGE_TYPE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-virtual_storage_type)
structure.

### `Path` [in]

A pointer to a valid path to the virtual disk image to open.

### `VirtualDiskAccessMask` [in]

A valid value of the
[VIRTUAL_DISK_ACCESS_MASK](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-virtual_disk_access_mask-r1) enumeration.

### `Flags` [in]

A valid combination of values of the
[OPEN_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-open_virtual_disk_flag) enumeration.

### `Parameters` [in, optional]

An optional pointer to a valid
[OPEN_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-open_virtual_disk_parameters) structure. Can
be **NULL**.

### `Handle` [out]

A pointer to the handle object that represents the open virtual disk.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS** (0) and the
*Handle* parameter contains a valid pointer to the new virtual disk object.

If the function fails, the return value is an error code and the value of the *Handle*
parameter is undefined. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

To prevent an open request failure when attempting to open a handle to a permanently attached virtual disk,
the following requirements apply:

* The *VirtualDiskAccessMask* parameter must include the
  **VIRTUAL_DISK_ACCESS_DETACH** (0x00040000) flag.
* Write access to the file must not be requested if the original open operation that created the permanently
  attached virtual disk only requested read access.

If the **OpenVirtualDisk** function fails with an error
code value of **ERROR_INVALID_PARAMETER** (87), the cause may be due to any of the following
conditions:

* The *VirtualStorageType* parameter is **NULL**.
* The *Path* parameter is **NULL**.
* The *VirtualDiskAccessMask* parameter is set to a value of
  `(VirtualDiskAccessMask & ~VIRTUAL_DISK_ACCESS_ALL)`.
* The *Flags* parameter is set to a value of
  `(Flags & ~(OPEN_VIRTUAL_DISK_FLAG_NO_PARENTS | OPEN_VIRTUAL_DISK_FLAG_BLANK_FILE))`.
* The **Version** member of the *Parameters* parameter is not
  set to **OPEN_VIRTUAL_DISK_VERSION_1** or **OPEN_VIRTUAL_DISK_VERSION_2**.

The host volume that contains the virtual disk image file cannot be compressed or EFS encrypted. This function
will fail with error **ERROR_UNSUPPORTED_COMPRESSION** (618) if the host volume has been
compressed or with error **ERROR_FILE_ENCRYPTED** (6002) if the host volume has been EFS
encrypted after the initial virtual disk creation.

The path pointed to by the *Path* parameter cannot be on a local network share (that
is a network share via loopback). This function will fail with error
**ERROR_FILE_SYSTEM_LIMITATION** (665) if the path is on a local network share. This
function will fail with error **ERROR_FILE_CORRUPT** (1392) if an ISO virtual disk is being
opened and the file size is not an even multiple of 2 KB (2,048 bytes), is at least 34 KB (34,816 bytes), or the
volume structure descriptor does not contain a known CDFS or UDFS volume identifier.

When an application is finished using the object handle returned in the *Handle*
parameter, use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the
handle.

CD and DVD image files (ISO) are not supported before Windows 8 and
Windows Server 2012.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[CreateVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-createvirtualdisk)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))