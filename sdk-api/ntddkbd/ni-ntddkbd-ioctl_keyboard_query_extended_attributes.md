# IOCTL_KEYBOARD_QUERY_EXTENDED_ATTRIBUTES IOCTL

## Description

The IOCTL_KEYBOARD_QUERY_EXTENDED_ATTRIBUTES request returns information about the extended keyboard attributes.

## Parameters

### Input buffer

**Parameters.DeviceIoControl.OutputBufferLength** is set to a value greater than or equal to the size, in bytes, of a [KEYBOARD_EXTENDED_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_extended_attributes) structure.

### Input buffer length

The size of a [KEYBOARD_EXTENDED_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_extended_attributes) structure.

### Output buffer

**AssociatedIrp.SystemBuffer** points to a client-allocated buffer that I8042prt uses to output a [KEYBOARD_EXTENDED_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_extended_attributes) structure.

### Output buffer length

The size of a [KEYBOARD_EXTENDED_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_extended_attributes) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member is set to the size, in bytes, of a [KEYBOARD_EXTENDED_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_extended_attributes) structure. Otherwise the **Information** member is set to zero.

The **Status** member is set to one of the following values:

## -STATUS_BUFFER_TOO_SMALL

**Parameters.DeviceIoControl.OutputBufferLength** is less than the size, in bytes, of a [KEYBOARD_EXTENDED_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_extended_attributes) structure.

## -STATUS_SUCCESS

The request completed successfully.

## See also

[KEYBOARD_EXTENDED_ATTRIBUTES structure](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_extended_attributes)

[IOCTL_KEYBOARD_QUERY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_attributes)

[IOCTL_KEYBOARD_QUERY_INDICATORS](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicators)

[IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_indicator_translation)

[IOCTL_KEYBOARD_QUERY_TYPEMATIC](https://learn.microsoft.com/windows/win32/api/ntddkbd/ni-ntddkbd-ioctl_keyboard_query_typematic)