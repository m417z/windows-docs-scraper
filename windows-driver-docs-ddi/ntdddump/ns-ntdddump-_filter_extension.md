# _FILTER_EXTENSION structure

## Description

The crash dump driver passes a pointer to a FILTER_EXTENSION structure when the filter driver callback routines are called.

## Members

### `DumpType`

This parameter indicates the type of dump that this instance of the filter driver is loaded on.

### `DeviceObject`

A pointer to the device object of the dump volume. This pointer points to the top of the dump volume stack.

### `Geometry`

The disk geometry of the dump device in [DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry) format.

### `DiskSize`

Size of the disk.

### `PartitionInfo`

The partition information in [DISK_PARTITION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_partition_info) format.

### `DumpData`

A pointer to the context data that is provided by the filter driver in [FILTER_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_initialization_data).

### `Size`

### `Flags`

## See also

[DISK_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_geometry)

[DISK_PARTITION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_partition_info)

[FILTER_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_initialization_data)