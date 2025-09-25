# _CHANGER_EXCHANGE_MEDIUM structure

## Description

The CHANGER_EXCHANGE_MEDIUM structure is used with the [IOCTL_CHANGER_EXCHANGE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_exchange_medium) request to exchange locations of two pieces of media.

## Members

### `Transport`

Indicates which transport element to use for the exchange operation. This member contains a structure of type [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element). The **ElementType** member of the CHANGER_ELEMENT structure must be assigned a value of **ChangerTransport**.

### `Source`

Indicates the element that contains the piece of media to be moved.

### `Destination1`

Indicates the destination of the piece of media originally at **Source**.

### `Destination2`

Indicates the destination of the piece of media originally at **Destination1**.

### `Flip1`

Indicates, when **TRUE**, that the piece of media moved to **Destination1** should be flipped. This member is valid only if the **Features0** member of the [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) structure is set to CHANGER_MEDIUM_FLIP. When **FALSE**, this member indicates that the media does not ready to be flipped.

### `Flip2`

Indicates, when **TRUE**, that the medium moved to **Destination2** should be flipped. This member is valid only if the **Features0** member of the GET_CHANGER_PARAMETERS structure is set to CHANGER_MEDIUM_FLIP. When **FALSE**, this member indicates that the media does not ready to be flipped.

## See also

[ChangerExchangeMedium](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerexchangemedium)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)

[IOCTL_CHANGER_EXCHANGE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_exchange_medium)