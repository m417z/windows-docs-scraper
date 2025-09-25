# MOUSE_ATTRIBUTES structure

## Description

MOUSE_ATTRIBUTES specifies the attributes of a mouse device.

## Members

### `MouseIdentifier`

Specifies one of the following types of mouse devices.

| Mouse type | Meaning |
| --- | --- |
| BALLPOINT_I8042_HARDWARE | i8042 port ballpoint mouse |
| BALLPOINT_SERIAL_HARDWARE | Serial port ballpoint mouse |
| MOUSE_HID_HARDWARE | HIDClass mouse |
| MOUSE_I8042_HARDWARE | i8042 port mouse |
| MOUSE_INPORT_HARDWARE | Inport (bus) mouse |
| MOUSE_SERIAL_HARDWARE | Serial port mouse |
| WHEELMOUSE_HID_HARDWARE | HIDClass wheel mouse |
| WHEELMOUSE_I8042_HARDWARE | i8042 port wheel mouse |
| WHEELMOUSE_SERIAL_HARDWARE | Serial port wheel mouse |

### `NumberOfButtons`

Specifies the number of buttons supported by a mouse. A mouse can have from two to five buttons. The default value is MOUSE_NUMBER_OF_BUTTONS.

### `SampleRate`

Specifies the rate, in reports per second, at which input from a PS/2 mouse is sampled. The default value is MOUSE_SAMPLE_RATE. This value is not used for USB devices.

### `InputDataQueueLength`

Specifies the size, in bytes, of the input data queue used by the port driver for a mouse device.

## Remarks

This structure is used with an [IOCTL_MOUSE_QUERY_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddmou/ni-ntddmou-ioctl_mouse_query_attributes) request to obtain the attributes of a mouse.

## See also

[IOCTL_MOUSE_QUERY_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/ntddmou/ni-ntddmou-ioctl_mouse_query_attributes)