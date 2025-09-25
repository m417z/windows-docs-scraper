# IOCTL_KEYBOARD_QUERY_TYPEMATIC IOCTL

## Description

The IOCTL_KEYBOARD_QUERY_TYPEMATIC request returns the keyboard typematic settings.

## Parameters

### Input buffer

**Parameters.DeviceIoControl.OutputBufferLength** is set to a value greater than or equal to the size, in bytes, of a [KEYBOARD_TYPEMATIC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters) structure.

### Input buffer length

The size of a [KEYBOARD_TYPEMATIC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters) structure.

### Output buffer

**AssociatedIrp.SystemBuffer** points to a client-allocated output buffer that I8042prt uses to output a [KEYBOARD_TYPEMATIC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters) structure.

### Output buffer length

The size of a [KEYBOARD_TYPEMATIC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a KEYBOARD_TYPEMATIC_PARAMETERS structure. Otherwise, **Information** is set to zero.

The **Status** member is set to one of the following values:

## -STATUS_BUFFER_TOO_SMALL

**Parameters.DeviceIoControl.OutputBufferLength** is less than the size, in bytes, of a KEYBOARD_TYPEMATIC_PARAMETERS structure.

## -STATUS_SUCCESS

The request completed successfully.

## See also

[IOCTL_KEYBOARD_QUERY_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_attributes)

[IOCTL_KEYBOARD_QUERY_INDICATORS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicators)

[IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicator_translation)

[KEYBOARD_TYPEMATIC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ntddkbd/ns-ntddkbd-keyboard_typematic_parameters)