# IOCTL_KEYBOARD_SET_TYPEMATIC IOCTL

## Description

The IOCTL_KEYBOARD_SET_TYPEMATIC request sets the keyboard typematic settings.

## Parameters

### Input buffer

**AssociatedIrp.SystemBuffer** points to a client-allocated buffer to input a [KEYBOARD_TYPEMATIC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters) structure. The client sets the typematic parameters in this structure.

**Parameters.DeviceIoControl.InputBufferLength** is set to a value greater than or equal to the size, in bytes, of a [KEYBOARD_TYPEMATIC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters) structure.

### Input buffer length

The size of a [KEYBOARD_TYPEMATIC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to zero.

The **Status** member is set to one of the following values:

## -STATUS_DEVICE_NOT_READY

The keyboard interrupt is not initialized.

## -STATUS_INVALID_PARAMETER

**Parameters.DeviceIoControl.InputBufferLength** is less than the size, in bytes, of a KEYBOARD_TYPEMATIC_PARAMETERS structure, or the specified typematic settings are invalid.

## -STATUS_IO_TIMEOUT

The request timed out.

## -STATUS_SUCCESS

The request completed successfully.

## See also

[IOCTL_KEYBOARD_SET_INDICATORS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_indicators)

[KEYBOARD_TYPEMATIC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters)