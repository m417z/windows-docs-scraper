# VDS_FILE_SYSTEM_FORMAT_SUPPORT_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of file systems that are supported for formatting volumes. These values are used in the **ulFlags** member of the [VDS_FILE_SYSTEM_FORMAT_SUPPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_format_support_prop) structure.

## Constants

### `VDS_FSS_DEFAULT:0x1`

The file system is the default file system to be used for formatting the volume.

### `VDS_FSS_PREVIOUS_REVISION:0x2`

The revision of the file system is not the latest revision supported for formatting the volume.

### `VDS_FSS_RECOMMENDED:0x4`

The file system is the recommended file system to be used for formatting the volume.

## Remarks

**Note** Additional constants might be added to the **VDS_FILE_SYSTEM_FORMAT_SUPPORT_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_FILE_SYSTEM_FORMAT_SUPPORT_FLAG** enumeration constant.

## See also

[IVdsDiskPartitionMF2::FormatPartitionEx2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdiskpartitionmf2-formatpartitionex2)

[IVdsVolumeMF2::FormatEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf2-formatex)

[VDS_FILE_SYSTEM_FORMAT_SUPPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_format_support_prop)