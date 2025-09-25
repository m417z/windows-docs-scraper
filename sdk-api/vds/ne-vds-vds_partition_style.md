# VDS_PARTITION_STYLE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of partition style values.

## Constants

### `VDS_PST_UNKNOWN:0`

An uninitialized disk. New disks or newly cleaned disks have this partitioning type.

### `VDS_PST_MBR:1`

The style is master boot record (MBR). If the value is **VDS_PST_MBR**, a DWORD signature identifies the disk. The identifier is unique on a single computer, but not unique across multiple computers. See the [VDS_PARTITION_INFO_MBR](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_mbr) structure.

### `VDS_PST_GPT:2`

The style is GUID partition table (GPT). If the value is **VDS_PST_GPT**, the disk has a GUID identifier. The GUID is guaranteed statistically to be unique across different computers. See the [VDS_PARTITION_INFO_GPT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_gpt) structure.

## Remarks

The [VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop) and
[VDS_PARTITION_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_prop) structures include a **VDS_PARTITION_STYLE** value as a member. Additionally, the [IVdsDisk::ConvertStyle](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-convertstyle) and [IVdsPack::AddDisk](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-adddisk) methods pass a **VDS_PARTITION_STYLE** value as an argument to indicate the partition style on a disk.

**Note** Additional constants might be added to the **VDS_PARTITION_STYLE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_PARTITION_STYLE** enumeration constant.

## See also

[IVdsDisk::ConvertStyle](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-convertstyle)

[IVdsPack::AddDisk](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-adddisk)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop)

[VDS_PARTITION_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_prop)