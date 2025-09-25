# _CHANGER_MOVE_MEDIUM structure

## Description

The CHANGER_MOVE_MEDIUM structure is used in conjunction with the [IOCTL_CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_move_medium) request to move a piece of media from a source element to a destination.

## Members

### `Transport`

Contains a structure of type [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element) that indicates which transport element to use for the move operation. The **ElementType** member of the CHANGER_ELEMENT structure must be assigned a value of **ChangerTransport**.

### `Source`

Contains a structure of type [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element) that indicates the element that contains the piece of media to be moved to **Destination**. The **ElementType** must be **ChangerDrive**, **ChangerTransport**, **ChangerSlot**, or **ChangerIEPort**.

### `Destination`

Contains a structure of type [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element) that indicates the destination of the piece of media originally at **Source**. The **ElementType** must be **ChangerDrive**, **ChangerTransport**, **ChangerSlot**, or **ChangerIEPort**.

### `Flip`

Indicates, when **TRUE**, that the piece of media should be flipped. When **FALSE** the media is not ready to be flipped. This member is valid only if CHANGER_MEDIUM_FLIP is set in the **Features0** member of the [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) structure.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[ChangerMoveMedium](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changermovemedium)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)

[IOCTL_CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_move_medium)