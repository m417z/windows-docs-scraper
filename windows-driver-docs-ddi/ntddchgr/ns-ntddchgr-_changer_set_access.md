# _CHANGER_SET_ACCESS structure

## Description

The CHANGER_SET_ACCESS structure is used in conjunction with the[IOCTL_CHANGER_SET_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_access) request to set the state of the device's import/export port (IEport), door, or keypad.

## Members

### `Element`

Contains a [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element) structure that specifies the element type and the zero-based address of the element to set. The **ElementType** member of the CHANGER_ELEMENT structure must be assigned one of the following values:

**ChangerIEPortChangerDoorChangerKeypad**

### `Control`

Specifies the operation to perform on the element. The **Features0** member of [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) indicates whether the changer supports a particular category of operation.

#### LOCK_ELEMENT

Lock the door, IEport, or keypad. Valid only if CHANGER_LOCK_UNLOCK is set.

#### UNLOCK_ELEMENT

Unlock the door, IEport, or keypad. Valid only if CHANGER_LOCK_UNLOCK is set.

#### EXTEND_IEPORT

Extend the IEport. Valid only if CHANGER_OPEN_IEPORT is set.

#### RETRACT_IEPORT

Retract the IEport. Valid only if CHANGER_CLOSE_IEPORT is set.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[ChangerSetAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changersetaccess)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)

[IOCTL_CHANGER_SET_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_access)