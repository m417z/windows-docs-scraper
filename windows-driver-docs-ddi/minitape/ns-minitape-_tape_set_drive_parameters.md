# _TAPE_SET_DRIVE_PARAMETERS structure (minitape.h)

## Description

The TAPE_SET_DRIVE_PARAMETERS structure is used in conjunction with the [IOCTL_TAPE_SET_DRIVE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_set_drive_params) request to adjust the configurable parameters of a tape drive.

## Members

### `ECC`

When set to **TRUE**, instructs the device to use hardware error correction. When **FALSE**, the device does not use hardware error correction.

### `Compression`

When set to **TRUE**, instructs the device to compress data prior to writing it. If a drive must be at beginning of partition before it can set compression (TAPE_DRIVE_SET_CMP_BOP_ONLY), the caller is responsible for positioning the drive before attempting to set compression. When **FALSE**, the device does not compress data prior to writing it.

### `DataPadding`

When set to **TRUE**, instructs the device to pad data with zeros. This is to keep the tape streaming until data is ready. When **FALSE**, the device does not pad data with zeros.

### `ReportSetmarks`

When set to **TRUE**, instructs the device to report setmarks encountered during read or space operations. When **FALSE**, the device does not report setmarks encountered during read or space operations.

### `EOTWarningZoneSize`

Indicates the size in bytes of the early warning zone toward the end of the tape in which the drive returns a check condition when it enters the zone.

## Remarks

The miniclass driver can ignore parameters its device does not support. The calling application is responsible for determining whether a device supports a particular feature before attempting to set it.

## See also

[IOCTL_TAPE_SET_DRIVE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_set_drive_params)

[TapeMiniSetDriveParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)