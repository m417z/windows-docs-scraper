# VDS_FILE_SYSTEM_FORMAT_SUPPORT_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Provides information about file systems that are supported for formatting volumes.

## Members

### `ulFlags`

Bitwise-OR of any of the values defined in the [VDS_FILE_SYSTEM_FORMAT_SUPPORT_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_file_system_format_support_flag) enumeration.

### `usRevision`

The revision of the file system, if any. This member is expressed as a 16-bit binary-coded decimal number, where a decimal point is implied between the second and third digits. For example, a value of 0x0250 indicates revision 2.50.

### `ulDefaultUnitAllocationSize`

Default allocation unit size, in bytes, that will be used by the file system for formatting the volume. This value must be a power of 2 and must also appear in the **rgulAllowedUnitAllocationSizes** member.

### `rgulAllowedUnitAllocationSizes`

A zero-terminated array of allocation unit sizes, in bytes, that are supported by the file system for formatting the volume. The case where the array will not be zero-terminated is if there are MAX_FS_ALLOWED_CLUSTER_SIZES_SIZE number of elements in the array. Each of the values in the array must be a power of 2.

### `wszName`

Null-terminated Unicode string indicating the name of the file system. Possible values include the following.

| Value | Meaning |
| --- | --- |
| L"CDFS" | CD-ROM file system (CDFS) |
| L"FAT" | FAT file system |
| L"FAT32" | FAT32 file system |
| L"NTFS" | NTFS file system |
| L"UDF" | Universal Disk Format (UDF) file system |

## Remarks

If an OEM partition is formatted as FAT or FAT32, the partition type does not change. If it is formatted with NTFS, the partition type changes to PARTITION_IFS (0x07). For information about partition types, see [CREATE_PARTITION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-create_partition_parameters).

## See also

[IVdsDiskPartitionMF2::FormatPartitionEx2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdiskpartitionmf2-formatpartitionex2)

[IVdsDiskPartitionMF::QueryPartitionFileSystemFormatSupport](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdiskpartitionmf-querypartitionfilesystemformatsupport)

[IVdsVolumeMF2::FormatEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf2-formatex)

[IVdsVolumeMF2::QueryFileSystemFormatSupport](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf2-queryfilesystemformatsupport)

[VDS_FILE_SYSTEM_FORMAT_SUPPORT_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_file_system_format_support_flag)