# _CHANGER_DEVICE_PROBLEM_TYPE enumeration

## Description

The CHANGER_DEVICE_PROBLEM_TYPE data type contains the values returned by the [ChangerPerformDiagnostics](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerperformdiagnostics) routine.

## Constants

### `DeviceProblemNone`

Indicates the device has no problem.

### `DeviceProblemHardware`

Indicates the device has had a hardware error.

### `DeviceProblemCHMError`

Indicates the Cartridge Handling Mechanism (CHM) has some problem.

### `DeviceProblemDoorOpen`

Indicates the changer's door is open.

### `DeviceProblemCalibrationError`

Indicates the changer has a calibration problem.

### `DeviceProblemTargetFailure`

Indicates a target failure has occurred.

### `DeviceProblemCHMMoveError`

Indicates the CHM is blocked and cannot move.

### `DeviceProblemCHMZeroError`

Indicates the CHM could not define zero on one or more of its axis.

### `DeviceProblemCartridgeInsertError`

Indicates an error occurred while loading a cartridge in the drive.

### `DeviceProblemPositionError`

Indicates the CHM has a problem positioning itself to some point.

### `DeviceProblemSensorError`

Indicates the device's sensors are malfunctioning.

### `DeviceProblemCartridgeEjectError`

Indicates an error occurred while unloading a cartridge.

### `DeviceProblemGripperError`

Indicates the media gripper has a problem.

### `DeviceProblemDriveError`

Indicates the changer's drive is malfunctioning.

## See also

[ChangerPerformDiagnostics](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerperformdiagnostics)

[WMI_CHANGER_PROBLEM_DEVICE_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmidata/ns-wmidata-_wmi_changer_problem_device_error)