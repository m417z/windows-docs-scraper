# KEYBOARD_INPUT_DATA structure

## Description

KEYBOARD_INPUT_DATA contains one packet of keyboard input data.

## Members

### `UnitId`

Specifies the unit number of a keyboard device. A keyboard device name has the format \Device\KeyboardPort*N*, where the suffix *N*  is the unit number of the device. For example, a device, whose name is \Device\KeyboardPort0, has a unit number of zero, and a device, whose name is \Device\KeyboardPort1, has a unit number of one.

### `MakeCode`

Specifies the scan code associated with a key press.

### `Flags`

Specifies a bitwise OR of one or more of the following flags that indicate whether a key was pressed or released, and other miscellaneous information.

| Value | Meaning |
| --- | --- |
| KEY_MAKE | The key was pressed. |
| KEY_BREAK | The key was released. |
| KEY_E0 | Extended scan code used to indicate special keyboard functions. |
| KEY_E1 | Extended scan code used to indicate special keyboard functions. |

### `Reserved`

Reserved for operating system use.

### `ExtraInformation`

Specifies device-specific information associated with a keyboard event.

## Remarks

In response to an [IRP_MJ_READ (Kbdclass)](https://learn.microsoft.com/previous-versions/ff542213(v=vs.85)) request, Kbdclass transfers zero or more **KEYBOARD_INPUT_DATA** structures from its internal data queue to the Win32 subsystem buffer.

## See also

[IRP_MJ_READ (Kbdclass)](https://learn.microsoft.com/previous-versions/ff542213(v=vs.85))

[KeyboardClassServiceCallback](https://learn.microsoft.com/previous-versions/ff542324(v=vs.85))