# VDS_DISK_EXTENT_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of disk extents types. The type can be a partition, volume, or free space.

## Constants

### `VDS_DET_UNKNOWN:0`

An extent of any unknown partition.

### `VDS_DET_FREE:1`

An extent of free space, including free space inside an extended partition.

### `VDS_DET_DATA:2`

An extent of any volume.

### `VDS_DET_OEM:3`

An extent of an OEM partition.

### `VDS_DET_ESP:4`

An extent of an ESP partition.

### `VDS_DET_MSR:5`

An extent of a MSR partition.

### `VDS_DET_LDM:6`

An extent of a LDM metadata partition.

### `VDS_DET_CLUSTER:7`

An extent of a cluster metadata partition.

### `VDS_DET_UNUSABLE:0x7fff`

An extent of unusable space on a disk. That is, space outside the four primary partitions (or three primary partitions plus one extended partition) on a basic MBR disk and space outside the dynamic disk public region.

## Remarks

ESP, MBR, and LDM metadata partitions are partition styles on GPT disks only.

The [VDS_DISK_EXTENT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_extent) structure includes a **VDS_DISK_EXTENT_TYPE** value as a member to indicate an existing disk extent type.

**Note** Additional constants might be added to the **VDS_DISK_EXTENT_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_DISK_EXTENT_TYPE** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_DISK_EXTENT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_extent)