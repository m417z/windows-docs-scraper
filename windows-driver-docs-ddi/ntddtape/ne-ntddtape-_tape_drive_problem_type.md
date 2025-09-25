# _TAPE_DRIVE_PROBLEM_TYPE enumeration (ntddtape.h)

## Description

The TAPE_DRIVE_PROBLEM_TYPE enumerator is used to report problems with the tape drive.

## Constants

### `TapeDriveProblemNone`

Indicates that there is no tape drive problem.

### `TapeDriveReadWriteWarning`

Indicates that the tape drive is having problems doing reads or writes. This is a warning.

### `TapeDriveReadWriteError`

Indicates that the tape drive is having problems doing reads or writes. This is a severe error.

### `TapeDriveReadWarning`

Indicates that the tape drive is having problems doing reads. This is a warning.

### `TapeDriveWriteWarning`

Indicates that the tape drive is having problems doing writes. This is a warning.

### `TapeDriveReadError`

Indicates that the tape drive is having problems doing reads. This is a severe error.

### `TapeDriveWriteError`

Indicates that the tape drive is having problems doing writes. This is a severe error.

### `TapeDriveHardwareError`

Indicates that the tape drive had a hardware error.

### `TapeDriveUnsupportedMedia`

Indicates that the media format is not supported.

### `TapeDriveScsiConnectionError`

Indicates that there is a SCSI cable or connection error.

### `TapeDriveTimetoClean`

Indicates that the tape drive requires cleaning.

### `TapeDriveCleanDriveNow`

Indicates that the tape drive requires cleaning.

### `TapeDriveMediaLifeExpired`

Indicates that the media life has expired. Media needs to be replaced.

### `TapeDriveSnappedTape`

Indicates that the tape has snapped.

## See also

[TAPE_WMI_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ns-ntddtape-_tape_wmi_operations)

[TapeMiniWMIControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)