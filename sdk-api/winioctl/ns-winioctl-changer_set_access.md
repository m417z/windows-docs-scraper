# CHANGER_SET_ACCESS structure

## Description

Contains information that the
[IOCTL_CHANGER_SET_ACCESS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_set_access) control code needs to set the state of the device's insert/eject port, door, or keypad.

## Members

### `Element`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that represents the changer element. The **ElementType** member can be one of the following values: ChangerDoor, ChangerIEPort, or ChangerKeypad.

### `Control`

The operation to be performed.

| Value | Meaning |
| --- | --- |
| **EXTEND_IEPORT**<br><br>2 | The element is to be extended. <br><br>Requires that **Features0** is CHANGER_OPEN_IEPORT. |
| **LOCK_ELEMENT**<br><br>0 | The element is to be locked. <br><br>Requires that **Features0** is CHANGER_LOCK_UNLOCK. |
| **RETRACT_IEPORT**<br><br>3 | The element is to be retracted. <br><br>Requires that **Features0** is CHANGER_CLOSE_IEPORT. |
| **UNLOCK_ELEMENT**<br><br>1 | The element is to be unlocked. <br><br>Requires that **Features0** is CHANGER_LOCK_UNLOCK. |

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element)

[IOCTL_CHANGER_SET_ACCESS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_set_access)