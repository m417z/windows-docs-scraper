# CHANGER_MOVE_MEDIUM structure

## Description

Contains information that the
[IOCTL_CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_move_medium) control code uses to move a piece of media to a destination.

## Members

### `Transport`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that indicates which transport element to use for the move operation.

### `Source`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that indicates the element that contains the media that is to be moved.

### `Destination`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that indicates the element that is the destination of the media originally at **Source**.

### `Flip`

If this member is **TRUE**, the media should be flipped. Otherwise, it should not. This member is valid only if the **Features0** member of the
[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_changer_parameters) structure is CHANGER_MEDIUM_FLIP.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element)

[IOCTL_CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_move_medium)