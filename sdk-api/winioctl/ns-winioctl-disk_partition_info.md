# DISK_PARTITION_INFO structure

## Description

Contains the disk partition information.

## Members

### `SizeOfPartitionInfo`

The size of this structure, in bytes.

### `PartitionStyle`

The format of a partition.

For more information, see [PARTITION_STYLE](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-partition_style).

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Mbr`

If **PartitionStyle** is **PARTITION_STYLE_MBR** (0), the union is a structure that contains information for a master boot record partition, which includes a disk signature and a checksum.

### `DUMMYUNIONNAME.Mbr.Signature`

MBR signature of the partition.

### `DUMMYUNIONNAME.Mbr.CheckSum`

### `DUMMYUNIONNAME.Gpt`

If **PartitionStyle** is **PARTITION_STYLE_GPT** (1), the union is a structure that contains information for a **GUID** partition table partition, which includes a disk identifier (**GUID**).

### `DUMMYUNIONNAME.Gpt.DiskId`

**GUID** of the GPT partition.

## See also

[DISK_GEOMETRY_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry_ex), [PARTITION_STYLE](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-partition_style)