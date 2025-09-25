# VDS_PARTITION_INFO_MBR structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the details of a master boot record (MBR) partition.

## Members

### `partitionType`

Byte value indicating the partition type.

### `bootIndicator`

If true, the partition is active and can be booted; otherwise, the partition cannot be used to boot the computer.

### `recognizedPartition`

If true, the operating system recognizes the partition style; otherwise, the partition style is unknown.

### `hiddenSectors`

Reserved sectors.

## Remarks

This structure is used in the **Mbr** member of the [VDS_PARTITION_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_prop) structure.

For information about partition types, see [CREATE_PARTITION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-create_partition_parameters).

## See also

[IVdsAdvancedDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsadvanceddisk)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop)

[VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2)

[VDS_PARTITION_INFO_GPT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_gpt)