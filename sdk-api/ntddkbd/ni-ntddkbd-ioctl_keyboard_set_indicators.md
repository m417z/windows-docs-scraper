# IOCTL_KEYBOARD_SET_INDICATORS IOCTL

## Description

The IOCTL_KEYBOARD_SET_INDICATORS request sets the keyboard indicators.

## Parameters

### Input buffer

**AssociatedIrp.SystemBuffer** points to a client-allocated buffer that inputs a [KEYBOARD_INDICATOR_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_indicator_parameters) structure. The client sets the indicator parameters in this structure.

**Parameters.DeviceIoControl.InputBufferLength** is set to a value greater than or equal to the size, in bytes, of a [KEYBOARD_INDICATOR_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_indicator_parameters) structure.

### Input buffer length

The size of a [KEYBOARD_INDICATOR_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_indicator_parameters) structure.

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

**Parameters.DeviceIoControl.InputBufferLength** is less than the size, in bytes, of a KEYBOARD_INDICATOR_PARAMETERS structure, or the specified indicator parameters are invalid.

## -STATUS_IO_TIMEOUT

The request timed out.

## -STATUS_SUCCESS

The request completed successfully.

## See also

[IOCTL_KEYBOARD_SET_TYPEMATIC](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_set_typematic)

[KEYBOARD_INDICATOR_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_indicator_parameters)