# CREATE_VIRTUAL_DISK_FLAG enumeration

## Description

Contains virtual hard disk (VHD) creation flags.

## Constants

### `CREATE_VIRTUAL_DISK_FLAG_NONE:0x0`

No special creation conditions; system defaults are used.

### `CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION:0x1`

Pre-allocate all physical space necessary for the size of the virtual disk.

### `CREATE_VIRTUAL_DISK_FLAG_PREVENT_WRITES_TO_SOURCE_DISK:0x2`

Take ownership of the source disk during create from source disk, to insure the source disk does not change
during the create operation. The source disk must also already be offline or read-only (or both). Ownership is
released when create is done. This also has a side-effect of disallowing concurrent create from same source
disk. Create will fail if ownership cannot be obtained or if the source disk is not already offline or
read-only. This flag is optional, but highly recommended for creates from source disk. No effect for other
types of create (no effect for create from source VHD; no effect for create without SourcePath).

**Windows 7 and Windows Server 2008 R2:** This flag is not supported for opening ISO virtual disks until Windows 8 and
Windows Server 2012.

### `CREATE_VIRTUAL_DISK_FLAG_DO_NOT_COPY_METADATA_FROM_PARENT:0x4`

Do not copy initial virtual disk metadata or block states from the parent VHD; this is useful if the parent
VHD is a stand-in file and the real parent will be explicitly set later.

**Windows 7 and Windows Server 2008 R2:** This flag is not supported for opening ISO virtual disks until Windows 8 and
Windows Server 2012.

### `CREATE_VIRTUAL_DISK_FLAG_CREATE_BACKING_STORAGE:0x8`

### `CREATE_VIRTUAL_DISK_FLAG_USE_CHANGE_TRACKING_SOURCE_LIMIT:0x10`

### `CREATE_VIRTUAL_DISK_FLAG_PRESERVE_PARENT_CHANGE_TRACKING_STATE:0x20`

### `CREATE_VIRTUAL_DISK_FLAG_VHD_SET_USE_ORIGINAL_BACKING_STORAGE:0x40`

### `CREATE_VIRTUAL_DISK_FLAG_SPARSE_FILE:0x80`

### `CREATE_VIRTUAL_DISK_FLAG_PMEM_COMPATIBLE:0x100`

## Remarks

The **CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION** flag is used for the creation of a fixed VHD.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))