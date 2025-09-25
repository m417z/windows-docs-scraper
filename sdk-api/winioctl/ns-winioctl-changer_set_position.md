# CHANGER_SET_POSITION structure

## Description

Contains information needed by the
[IOCTL_CHANGER_SET_POSITION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_set_position) control code to set the changer's robotic transport mechanism to the specified element address.

## Members

### `Transport`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that indicates the transport to be moved. The **ElementType** member must be ChangerTransport.

### `Destination`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that indicates the final destination of the transport. The **ElementType** member must be one of the following values: ChangerSlot, ChangerDrive, or ChangerIEPort.

### `Flip`

If this member is **TRUE**, the media currently carried by **Transport** should be flipped. Otherwise, it should not. This member is valid only if the **Features0** member of the
[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_changer_parameters) structure is CHANGER_MEDIUM_FLIP.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element)

[IOCTL_CHANGER_SET_POSITION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_set_position)