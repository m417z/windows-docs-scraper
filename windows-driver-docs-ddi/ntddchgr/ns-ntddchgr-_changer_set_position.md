# _CHANGER_SET_POSITION structure

## Description

The CHANGER_SET_POSITION structure is used in conjunction with the[IOCTL_CHANGER_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_position) request to set the changer's robotic transport mechanism to the specified element address.

## Members

### `Transport`

Contains a structure of type [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element) that indicates the transport element to move. The **ElementType** member of the CHANGER_ELEMENT structure must be assigned a value of **ChangerTransport**.

### `Destination`

Contains a structure of type [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element) that indicates the final destination of the transport element. **ElementType** must be **ChangerSlot**, **ChangerDrive**, or **ChangerIEPort**.

### `Flip`

Indicates, when **TRUE**, that the **Transport** should be flipped. When **FALSE** this member indicates that the transport is not ready to be flipped. This member is applicable only if CHANGER_MEDIUM_FLIP is set in the **Features0** member of the [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) structure.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[ChangerSetPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changersetposition)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)

[IOCTL_CHANGER_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_position)