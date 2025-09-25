# _ELEMENT_TYPE enumeration

## Description

The ELEMENT_TYPE enumeration provides a list of changer element types defined by the *SCSI-3* specification.

## Constants

### `AllElements`

Indicates all elements of a changer, including its robotic transport, drives, slots, and IEport. **AllElements** is valid only in a [ChangerGetElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetelementstatus) or [ChangerInitializeElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerinitializeelementstatus) call.

### `ChangerTransport`

Indicates the changer's robotic transport element, which is used to move media between IEports, slots, and drives.

### `ChangerSlot`

Indicates a storage element, which is a slot in the changer in which media is stored when not mounted in a drive.

### `ChangerIEPort`

Indicates an import/export element (IEport), which is a single or multiple-cartridge access port in some changers. An element is an IEport only if it is possible to move a piece of media from a slot to the IEport.

### `ChangerDrive`

Indicates a data transfer element where data can be read from and written to media.

### `ChangerDoor`

Indicates a mechanism that provides access to all media in a changer at one time (as compared to an IEport that provides access to one or more, but not all, media). For example, a large front door or a magazine that contains all media in the changer are elements of this type. **ChangerDoor** is valid only in a [ChangerSetAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changersetaccess) call.

### `ChangerKeypad`

Indicates the keypad or other input control on the front panel of a changer. **ChangerKeypad** is valid only in a [ChangerSetAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changersetaccess) call.

### `ChangerMaxElement`

Indicates the upper limit of the enumerators in this enumeration.

## See also

[ChangerGetElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetelementstatus)

[ChangerInitializeElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerinitializeelementstatus)

[ChangerSetAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changersetaccess)