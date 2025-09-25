# CHANGE_PARTITION_TYPE_PARAMETERS structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Describes parameters to be used when changing a partition's type.

## Members

### `style`

A value from the [VDS_PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_style) enumeration that describes the disk's partition style.

### `MbrPartInfo`

Contains information for a Master Boot Record partition.

### `MbrPartInfo.partitionType`

Byte value indicating the partition type to which to change the partition.

### `GptPartInfo`

Contains information for a GUID Partitioning Table partition.

### `GptPartInfo.partitionType`

 GUID indicating the partition type to which to change the partition.

**Note** Only the basic data partition type is allowed.

## Remarks

For information about partition types, see [CREATE_PARTITION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-create_partition_parameters).

## See also

[IVdsAdvancedDisk2::ChangePartitionType](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk2-changepartitiontype)