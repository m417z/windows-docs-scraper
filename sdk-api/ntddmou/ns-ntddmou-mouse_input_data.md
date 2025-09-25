# MOUSE_INPUT_DATA structure

## Description

MOUSE_INPUT_DATA contains one packet of mouse input data.

## Members

### `UnitId`

Specifies the unit number of the mouse device. A mouse [device name](https://learn.microsoft.com/windows-hardware/drivers/kernel/nt-device-names) has the format \Device\PointerPort*N*, where the suffix *N*  is the unit number of the device. For example, a device, whose name is \Device\PointerPort0, has a unit number of zero, and a device, whose name is \Device\PointerPort1, has a unit number of one.

### `Flags`

Specifies a bitwise OR of one or more of the following mouse indicator flags.

| Value | Meaning |
| --- | --- |
| MOUSE_MOVE_RELATIVE | The **LastX** and **LastY** are set relative to the previous location. |
| MOUSE_MOVE_ABSOLUTE | The **LastX** and **LastY** values are set to absolute values. |
| MOUSE_VIRTUAL_DESKTOP | The mouse coordinates are mapped to the virtual desktop. |
| MOUSE_ATTRIBUTES_CHANGED | The mouse attributes have changed. The other data in the structure is not used. |
| MOUSE_MOVE_NOCOALESCE | (Windows Vista and later) WM_MOUSEMOVE notification messages will not be coalesced. By default, these messages are coalesced.<br><br>For more information about WM_MOUSEMOVE notification messages, see the Microsoft Software Development Kit (SDK) documentation |

### `Buttons`

Specifies both **ButtonFlags** and **ButtonData** values. Mouclass uses **Buttons** in its interrupt service routine to do a fast single memory access to **ButtonFlags** and **ButtonData**.

### `ButtonFlags`

Specifies the transition state of the mouse buttons.

| Flag | Meaning |
| --- | --- |
| MOUSE_LEFT_BUTTON_DOWN | The left mouse button changed to down. |
| MOUSE_LEFT_BUTTON_UP | The left mouse button changed to up. |
| MOUSE_RIGHT_BUTTON_DOWN | The right mouse button changed to down. |
| MOUSE_RIGHT_BUTTON_UP | The right mouse button changed to up. |
| MOUSE_MIDDLE_BUTTON_DOWN | The middle mouse button changed to down. |
| MOUSE_MIDDLE_BUTTON_UP | The middle mouse button changed to up. |
| MOUSE_BUTTON_4_DOWN | The fourth mouse button changed to down. |
| MOUSE_BUTTON_4_UP | The fourth mouse button changed to up. |
| MOUSE_BUTTON_5_DOWN | The fifth mouse button changed to down. |
| MOUSE_BUTTON_5_UP | The fifth mouse button changed to up. |
| MOUSE_WHEEL | Mouse wheel data is present. |
| MOUSE_HWHEEL | Mouse horizontal wheel data is present. |

### `ButtonData`

Specifies mouse wheel data, if MOUSE_WHEEL is set in ButtonFlags.

### `RawButtons`

Specifies the raw state of the mouse buttons. The Win32 subsystem does not use this member.

### `LastX`

Specifies the signed relative or absolute motion in the x direction.

### `LastY`

Specifies the signed relative or absolute motion in the y direction.

### `ExtraInformation`

Specifies device-specific information.

## Remarks

In response to [IRP_MJ_READ (Mouclass)](https://learn.microsoft.com/previous-versions/ff542215(v=vs.85)) requests, Mouclass transfers zero or more **MOUSE_INPUT_DATA** structures from its internal data queue to the Microsoft Win32 subsystem buffer.

## See also

[IRP_MJ_READ (Mouclass)](https://learn.microsoft.com/previous-versions/ff542215(v=vs.85))

[MouseClassServiceCallback](https://learn.microsoft.com/previous-versions/ff542394(v=vs.85))