# VDS_PARTITION_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
properties of a partition.

## Members

### `PartitionStyle`

The styles enumerated by [VDS_PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_style).
The style is either master boot record (VDS_PST_MBR) or GUID partition table (VDS_PST_GPT). This member is the
discriminant for the union.

### `ulFlags`

The partition flags enumerated by [VDS_PARTITION_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_flag).

### `ulPartitionNumber`

The number assigned to the partition.

### `ullOffset`

The partition offset.

### `ullSize`

The size of the partition in bytes.

### `Mbr`

If **PartitionStyle** is **VDS_PST_MBR**, MBR-specific partition
details. For more information see
[VDS_PARTITION_INFO_MBR](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_mbr).

### `Gpt`

If **PartitionStyle** is **VDS_PST_GPT**, GPT-specific partition
details. For more information see
[VDS_PARTITION_INFO_GPT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_gpt).

## Remarks

The [IVdsAdvancedDisk::GetPartitionProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-getpartitionproperties)
and [IVdsAdvancedDisk::QueryPartitions](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-querypartitions)
methods return this structure to report the property details of a partition.

## See also

[IVdsAdvancedDisk::GetPartitionProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-getpartitionproperties)

[IVdsAdvancedDisk::QueryPartitions](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-querypartitions)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_PARTITION_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_flag)

[VDS_PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_style)