# VDS_FILE_SYSTEM_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid flags for a file system.

## Constants

### `VDS_FSF_SUPPORT_FORMAT:0x1`

If set, the file system supports format. The drop-down list of a user interface should display only file systems that support formatting.

### `VDS_FSF_SUPPORT_QUICK_FORMAT:0x2`

If set, the file system supports quick format.

### `VDS_FSF_SUPPORT_COMPRESS:0x4`

If set, the file system supports file compression.

### `VDS_FSF_SUPPORT_SPECIFY_LABEL:0x8`

If set, the file system supports file system labels.

### `VDS_FSF_SUPPORT_MOUNT_POINT:0x10`

If set, the file system supports mounted folders.

### `VDS_FSF_SUPPORT_REMOVABLE_MEDIA:0x20`

If set, the file system supports removable media.

### `VDS_FSF_SUPPORT_EXTEND:0x40`

If set, the file system supports extending volumes.

### `VDS_FSF_ALLOCATION_UNIT_512:0x10000`

If set, the file system supports allocation units of 512 bytes.

### `VDS_FSF_ALLOCATION_UNIT_1K:0x20000`

If set, the file system supports allocation units of 1 kilobyte.

### `VDS_FSF_ALLOCATION_UNIT_2K:0x40000`

If set, the file system supports allocation units of 2 kilobytes.

### `VDS_FSF_ALLOCATION_UNIT_4K:0x80000`

If set, the file system supports allocation units of 4 kilobytes.

### `VDS_FSF_ALLOCATION_UNIT_8K:0x100000`

If set, the file system supports allocation units of 8 kilobytes.

### `VDS_FSF_ALLOCATION_UNIT_16K:0x200000`

If set, the file system supports allocation units of 16 kilobytes.

### `VDS_FSF_ALLOCATION_UNIT_32K:0x400000`

If set, the file system supports allocation units of 32 kilobytes.

### `VDS_FSF_ALLOCATION_UNIT_64K:0x800000`

If set, the file system supports allocation units of 64 kilobytes.

### `VDS_FSF_ALLOCATION_UNIT_128K:0x1000000`

If set, the file system supports allocation units of 128 kilobytes.

### `VDS_FSF_ALLOCATION_UNIT_256K:0x2000000`

If set, the file system supports allocation units of 256 kilobytes.

## Remarks

This enumeration provides the values for the *ulFlags* member of the [VDS_FILE_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_prop) structure. The [SetFileSystemFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-setfilesystemflags) method passes the value as an argument to set the **VDS_FPF_COMPRESSED** flag.

**Note** Additional constants might be added to the **VDS_FILE_SYSTEM_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_FILE_SYSTEM_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_FILE_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_prop)