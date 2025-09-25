# VDS_FORMAT_OPTION_FLAGS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid formatting options for the [IVdsDiskPartitionMF2::FormatPartitionEx2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdiskpartitionmf2-formatpartitionex2) method.

## Constants

### `VDS_FSOF_NONE:0`

No options are specified.

### `VDS_FSOF_FORCE:0x1`

The format operation should be forced, even if the partition is in use.

### `VDS_FSOF_QUICK:0x2`

Perform a quick format operation. A quick format does not verify each sector on the volume.

### `VDS_FSOF_COMPRESSION:0x4`

Enable compression on the newly formatted file system volume. Compression is a feature of the NTFS file system; it cannot be set for other file systems such as FAT or FAT32.

### `VDS_FSOF_DUPLICATE_METADATA:0x8`

Forces duplication of metadata for UDF 2.5 and above.

## Remarks

**Note** Additional constants might be added to the **VDS_FORMAT_OPTION_FLAGS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_FORMAT_OPTION_FLAGS** enumeration constant.

## See also

[IVdsDiskPartitionMF2::FormatPartitionEx2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdiskpartitionmf2-formatpartitionex2)