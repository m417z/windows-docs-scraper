# VDS_FILE_SYSTEM_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid types for a file system.

## Constants

### `VDS_FST_UNKNOWN:0`

The file system is unknown. The [IVdsVolumeMF::GetFileSystemProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-getfilesystemproperties) method returns this value in the [VDS_FILE_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_prop) structure for BitLocker-encrypted volumes.

### `VDS_FST_RAW`

The file system is raw.

### `VDS_FST_FAT`

The file system is file allocation table (FAT).

### `VDS_FST_FAT32`

The file system is file allocation table for 32-bit computers (FAT32).

### `VDS_FST_NTFS`

The file system is the NT file system (NTFS).

### `VDS_FST_CDFS`

The file system is the CD-ROM file system (CDFS).

### `VDS_FST_UDF`

The file system is Universal Disk Format (UDF).

### `VDS_FST_EXFAT`

The file system is extended file allocation table (exFAT).

**Windows Server 2008, Windows Vista and Windows Server 2003:** The VDS_FST_EXFAT file type value is not supported.

### `VDS_FST_CSVFS`

### `VDS_FST_REFS`

## Remarks

The [VDS_FILE_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_prop) structure includes a **VDS_FILE_SYSTEM_TYPE** value as a member to indicate an existing file system type.

**Note** Additional constants might be added to the **VDS_FILE_SYSTEM_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_FILE_SYSTEM_TYPE** enumeration constant.

## See also

[IVdsAdvancedDisk::FormatPartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-formatpartition)

[IVdsVolumeMF::Format](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-format)

[IVdsVolumeMF::GetFileSystemProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-getfilesystemproperties)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_FILE_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_prop)

[VDS_FILE_SYSTEM_TYPE_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_type_prop)

[VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop)