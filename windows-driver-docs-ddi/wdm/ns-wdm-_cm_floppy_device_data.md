# _CM_FLOPPY_DEVICE_DATA structure

## Description

The **CM_FLOPPY_DEVICE_DATA** structure defines a device-type-specific data record that is stored in the \\Registry\Machine\Hardware\Description tree for a floppy controller if the system can collect this information during the boot process.

## Members

### `Version`

The version number of this structure.

### `Revision`

The revision of this structure.

### `Size`

The floppy disk density size.

### `MaxDensity`

The maximum density.

### `MountDensity`

The mount density.

### `StepRateHeadUnloadTime`

The step rate head unload time in milliseconds.

### `HeadLoadTime`

The head load time in milliseconds.

### `MotorOffTime`

The motor off time in seconds.

### `SectorLengthCode`

Indicates the sector size as an exponent in the formula ((2***code*) * 128).

### `SectorPerTrack`

The number of sectors per track.

### `ReadWriteGapLength`

The read/write gap length, in bytes.

### `DataTransferLength`

The data transfer length, in bytes, not including the synchronization field.

### `FormatGapLength`

The format gap length, in bytes.

### `FormatFillCharacter`

The format fill character.

### `HeadSettleTime`

The head settle time in milliseconds.

### `MotorSettleTime`

The motor settle time in milliseconds.

### `MaximumTrackValue`

The maximum track number on the media. Track numbers are zero-based values.

### `DataTransferRate`

The value written to the Datarate register before accessing the media.

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[IoQueryDeviceDescription](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[IoReportResourceUsage](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)