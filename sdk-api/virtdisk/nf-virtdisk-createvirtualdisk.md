# CreateVirtualDisk function

## Description

Creates a virtual hard disk (VHD) image file, either using default parameters or using an existing
virtual disk or physical disk.

## Parameters

### `VirtualStorageType` [in]

A pointer to a [VIRTUAL_STORAGE_TYPE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-virtual_storage_type) structure
that contains the desired disk type and vendor information.

### `Path` [in]

A pointer to a valid string that represents the path to the new virtual disk image file.

### `VirtualDiskAccessMask` [in]

The [VIRTUAL_DISK_ACCESS_MASK](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-virtual_disk_access_mask-r1) value to use
when opening the newly created virtual disk file. If the **Version** member of the
*Parameters* parameter is set to
**CREATE_VIRTUAL_DISK_VERSION_2** then only the
**VIRTUAL_DISK_ACCESS_NONE** (0) value may be specified.

### `SecurityDescriptor` [in, optional]

An optional pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) to apply to the virtual
disk image file. If this parameter is **NULL**, the parent directory's security descriptor
will be used.

### `Flags` [in]

Creation flags, which must be a valid combination of the
[CREATE_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-create_virtual_disk_flag) enumeration.

### `ProviderSpecificFlags` [in]

Flags specific to the type of virtual disk being created. May be zero if none are required.

### `Parameters` [in]

A pointer to a valid
[CREATE_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-create_virtual_disk_parameters) structure
that contains creation parameter data.

### `Overlapped` [in, optional]

An optional pointer to a valid [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure
if [asynchronous](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output) operation
is desired.

### `Handle` [out]

A pointer to the handle object that represents the newly created virtual disk.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS** and the
*Handle* parameter contains a valid pointer to the new virtual disk object.

If the function fails, the return value is an error code and the value of the *Handle*
parameter is undefined. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

If the **CreateVirtualDisk** function fails with an
error code value of **ERROR_INVALID_PARAMETER**, the cause may be due to any of the
following conditions:

* The *VirtualStorageType* parameter is **NULL**.
* The *Parameters* parameter is **NULL**.
* The **Version** member of the *Parameters* parameter is not
  set to **CREATE_VIRTUAL_DISK_VERSION_1** or
  **CREATE_VIRTUAL_DISK_VERSION_2**.
* The **Version** member of the *Parameters* parameter is set
  to **CREATE_VIRTUAL_DISK_VERSION_2** but the
  *VirtualDiskAccessMask* parameter is not set to
  **VIRTUAL_DISK_ACCESS_NONE**.
* The **BlockSizeInBytes** member of the *Parameters*
  parameter is not set to **CREATE_VIRTUAL_DISK_PARAMETERS_DEFAULT_BLOCK_SIZE** (0),
  0x80000 (512 KB), or 0x200000 (2 MB).
* The **MaximumSize** member of the *Parameters* parameter is
  less than 3 MB.
* The **MaximumSize** member of the *Parameters* parameter is
  not aligned with the value of the **SectorSizeInBytes** member.
* The *VirtualDiskAccessMask* parameter is set to a value of
  `(VirtualDiskAccessMask & ~VIRTUAL_DISK_ACCESS_ALL)`.
* The *Flags* parameter is larger than
  **CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION**.

The host volume containing the new virtual disk image file cannot be compressed or EFS encrypted.

When creating the various types of virtual disks, the following combinations of creation parameters are
recommended:

* The **CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION** flag should be
  specified.
* **ParentPath** should not be specified.
* **SourcePath** can be specified if desired.

* The **CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION** flag should not be
  specified.
* **ParentPath** should not be specified.
* **SourcePath** can be specified if desired.

* The **CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION** flag should not be
  specified.
* **ParentPath** should be specified.
* **SourcePath** should not be specified.

The **CreateVirtualDisk** function can also be used
as a mechanism for converting one type of virtual disk to another, or a physical disk to a virtual disk. This is
accomplished through the use of the **SourcePath** member of the
[CREATE_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-create_virtual_disk_parameters) structure
to pre-populate the new virtual disk with block data from the source disk.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))