# CHANGER_EXCHANGE_MEDIUM structure

## Description

Contains information the
[IOCTL_CHANGER_EXCHANGE_MEDIUM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_exchange_medium) control code uses to move a piece of media to a destination, and the piece of media originally in the first destination to a second destination.

## Members

### `Transport`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that indicates which transport element to use for the exchange operation. The **ElementType** member of this structure must be ChangerTransport.

### `Source`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that indicates the element that contains the media that is to be moved.

### `Destination1`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that indicates the element that is the destination of the media originally at **Source**.

### `Destination2`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that indicates the element that is the destination of the media originally at **Destination1**.

### `Flip1`

If this member is **TRUE**, the medium at **Destination1** should be flipped. Otherwise, it should not. This member is valid only if the **Features0** member of the
[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_changer_parameters) structure is CHANGER_MEDIUM_FLIP.

### `Flip2`

If this member is **TRUE**, the medium at **Destination2** should be flipped. Otherwise, it should not. This member is valid only if the **Features0** member of the
[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_changer_parameters) structure is CHANGER_MEDIUM_FLIP.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element)

[IOCTL_CHANGER_EXCHANGE_MEDIUM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_exchange_medium)