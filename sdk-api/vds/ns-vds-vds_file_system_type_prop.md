# VDS_FILE_SYSTEM_TYPE_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of a file system type.

## Members

### `type`

The file system types enumerated by [VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type). Valid types are FAT, FAT32, NTFS, CDFS and UDF.

### `wszName`

 The file system name.

### `ulFlags`

The file system flags enumerated by [VDS_FILE_SYSTEM_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_file_system_flag).

### `ulCompressionFlags`

The valid allocation unit sizes used for compression.

### `ulMaxLableLength`

The maximum length for a label name.

### `pwszIllegalLabelCharSet`

A string containing all characters that are not valid for this file system type.

## Remarks

The [IVdsService::QueryFileSystemTypes](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-queryfilesystemtypes) method returns this structure to report the property details of a file-system type.

## See also

[IVdsService::QueryFileSystemTypes](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-queryfilesystemtypes)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_FILE_SYSTEM_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_file_system_flag)

[VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type)