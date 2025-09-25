# _CM_INT13_DRIVE_PARAMETER structure

## Description

The **CM_INT13_DRIVE_PARAMETER** structure defines a device-type-specific data record that is stored in the \\Registry\Machine\Hardware\Description tree for a disk controller if the system can collect this information during the boot process.

## Members

### `DriveSelect`

The drive selected value.

### `MaxCylinders`

The maximum number of cylinders.

### `SectorsPerTrack`

The number of sectors per track.

### `MaxHeads`

The maximum number of heads.

### `NumberDrives`

The number of drives.

## See also

[IoQueryDeviceDescription](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[IoReportResourceUsage](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)