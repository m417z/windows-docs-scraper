# DISK_INT13_INFO structure

## Description

Contains standard Int13 drive geometry parameters.

## Members

### `DriveSelect`

The letter that is related to the specified partition or hard disk. For valid values, see the BIOS documentation.

### `MaxCylinders`

The maximum number of cylinders per head. For valid values, see the BIOS documentation.

### `SectorsPerTrack`

The number of sectors per track. For valid values, see the BIOS documentation.

### `MaxHeads`

The maximum number of heads for this hard disk. For valid values, see the BIOS documentation.

### `NumberDrives`

The number of drives. For valid values, see the BIOS documentation.

## See also

[DISK_DETECTION_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-disk_detection_info)