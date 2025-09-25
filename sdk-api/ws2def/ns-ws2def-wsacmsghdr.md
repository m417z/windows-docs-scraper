# WSACMSGHDR structure

## Description

The CMSGHDR structure defines the header for a control data object that is associated with a
datagram.

## Members

### `cmsg_len`

The number of bytes from the beginning of the CMSGHDR structure to the end of the control data.

**Note** The value of the
**cmsg_len** member does not account for any padding that may follow the
control data.

### `cmsg_level`

The protocol that originated the control information.

### `cmsg_type`

The protocol-specific type of control information.

## Remarks

The control information data that is associated with a datagram is made up of one or more control data
objects. Each object begins with a CMSGHDR structure.

## See also

[WSK_DATAGRAM_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/ns-wsk-_wsk_datagram_indication)

[WskReceiveFrom](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_receive_from)

[WskSendTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_send_to)