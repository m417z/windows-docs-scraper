## Description

The **DISK_SPACE_INFORMATION** structure contains information about the disk space for a particular volume.

## Members

### `ActualTotalAllocationUnits`

The `ActualTotalAllocationUnits` is the total volume size without considering Quota setting.

### `ActualAvailableAllocationUnits`

The `ActualTotalAllocationUnits` is the available space for the volume without considering Quota setting.

### `ActualPoolUnavailableAllocationUnits`

The `ActualPoolUnavailableAllocationUnits` is the unavailable space for the volume due to insufficient free pool space

### `CallerTotalAllocationUnits`

The `CallerTotalAllocationUnits` is the total volume size limited by Quota setting.

### `CallerAvailableAllocationUnits`

The `CallerAvailableAllocationUnits` is the available space for the volume limited by Quota setting.

### `CallerPoolUnavailableAllocationUnits`

The `CallerAvailableAllocationUnits` is the unavailable space for the volume due to insufficient free pool space.

### `UsedAllocationUnits`

The used space of the volume.

### `TotalReservedAllocationUnits`

Total reserved space.

### `VolumeStorageReserveAllocationUnits`

A special type of reserved space for per-volume storage reserve. This is included in the `TotalReservedAllocationUnits`.

### `AvailableCommittedAllocationUnits`

The space that has been committed by storage pool but has not been allocated by file system.

### `PoolAvailableAllocationUnits`

Available space in corresponding storage pool. If the volume is not a spaces volume, the `PoolAvailableAllocationUnits` is set to `0`.

### `SectorsPerAllocationUnit`

The number of sectors per allocation unit for the volume.

### `BytesPerSector`

The number of bytes per sector for the volume.

## Remarks

## See also

[GetDiskSpaceInformationA](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getdiskspaceinformationa)

[GetDiskSpaceInformationW](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getdiskspaceinformationw)