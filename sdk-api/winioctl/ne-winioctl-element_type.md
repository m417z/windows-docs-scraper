# ELEMENT_TYPE enumeration

## Description

Specifies the element type of a changer device.

## Constants

### `AllElements`

All elements of a changer, including its robotic transport, drives, slots, and insert/eject ports. This value is valid only with
[IOCTL_CHANGER_GET_ELEMENT_STATUS](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_changer_get_element_status) or [IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_changer_initialize_element_status).

### `ChangerTransport`

Robotic transport element, which is used to move media between insert/eject ports, slots, and drives.

### `ChangerSlot`

Storage element, which is a slot in the changer in which media is stored when not mounted in a drive.

### `ChangerIEPort`

Insert/eject port, which is a single- or multiple-cartridge access port in some changers. An element is an insert/eject port only if it is possible to move a piece of media from a slot to the insert/eject port.

### `ChangerDrive`

Data transfer element where data can be read from and written to media.

### `ChangerDoor`

Mechanism that provides access to all media in a changer at one time (as compared to an IEport that provides access to one or more, but not all, media). For example, a large front door or a magazine that contains all media in the changer is an element of this type. This value is valid only with [IOCTL_CHANGER_SET_ACCESS](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_changer_set_access).

### `ChangerKeypad`

Keypad or other input control on the front panel of a changer. This value is valid only with [IOCTL_CHANGER_SET_ACCESS](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_changer_set_access).

### `ChangerMaxElement`

## See also

* [CHANGER_ELEMENT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-changer_element)