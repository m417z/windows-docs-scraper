# _CHANGER_ELEMENT structure

## Description

The CHANGER_ELEMENT structure contains a description of a changer element.

## Members

### `ElementType`

Indicates the type of element. Can be one of the following values taken from the [ELEMENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ne-ntddchgr-_element_type) enumeration.

#### AllElements

All elements of a changer, including its robotic transport, drives, slots, and IEport. **AllElements** is valid only in a **ChangerGetElementStatus** or **ChangerInitializeElementStatus** call.

#### ChangerTransport

The changer's robotic transport element, which is used to move media between IEports, slots, and drives.

#### ChangerSlot

A storage element, which is a slot in the changer in which media is stored when not mounted in a drive.

#### ChangerIEPort

An import/export element (IEport), which is a single or multiple-cartridge access port in some changers. An element is an IEport only if it is possible to move a piece of media from a slot to the IEport.

#### ChangerDrive

A data transfer element where data can be read from and written to media.

#### ChangerDoor

A mechanism that provides access to all media in a changer at one time (as compared to an IEport that provides access to one or more, but not all, media). For example, a large front door or a magazine that contains all media in the changer are elements of this type. **ChangerDoor** is valid only in a **ChangerSetAccess** call.

#### ChangerKeypad

The keypad or other input control on the front panel of a changer. **ChangerKeypad** is valid only in a **ChangerSetAccess** call.

### `ElementAddress`

Indicates the element's zero-based address used by the system. A changer miniclass driver is responsible for translating this address to the device-specific address used by the changer.

## Remarks

CHANGER_ELEMENT is used by both the changer class driver and a changer miniclass driver to describe a changer element.

On input, a changer miniclass driver must translate the zero-based address in **ElementAddress** to a device-specific address before accessing the element. On output, the driver must translate a device-specific address to the zero-based equivalent before filling in **ElementAddress**.

## See also

[CHANGER_ELEMENT_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_list)

[CHANGER_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_status)

[ELEMENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ne-ntddchgr-_element_type)