# VDS_PARTITION_INFO_GPT structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines details of a GUID partition table (GPT) partition.

## Members

### `partitionType`

GUID for the partition type.

### `partitionId`

GUID for the partition.

### `attributes`

Attributes of the partition.

### `name`

Name of the partition.

## Remarks

This structure is used in the **Gpt** member of the [VDS_PARTITION_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_prop) structure.

 A GPT table is sector-aligned.

For information about partition types and attributes, see [CREATE_PARTITION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-create_partition_parameters).

## See also

[IVdsAdvancedDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop)

[VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2)

[VDS_PARTITION_INFO_MBR](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_mbr)