# _WSK_DATAGRAM_INDICATION structure

## Description

The WSK_DATAGRAM_INDICATION structure describes a datagram that has been received on a datagram
socket.

## Members

### `Next`

A pointer to the next WSK_DATAGRAM_INDICATION structure in a linked list of
WSK_DATAGRAM_INDICATION structures. If this member is **NULL**, this structure is the last
WSK_DATAGRAM_INDICATION structure in the linked list.

### `Buffer`

A WSK_BUF structure that describes a datagram that has been received on the socket.

### `ControlInfo`

The control information that is associated with the received datagram. The control information
data that is associated with a datagram is made up of one or more control data objects, each of which
begins with a
[CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr) structure. If there is no control
information present for the received datagram, this member is **NULL**.

### `ControlInfoLength`

The size of the control information that is associated with the received datagram. If this value
is zero, there is no control information present for the datagram.

### `RemoteAddress`

A pointer to a buffer that contains the remote transport address from which the received datagram
originated. The buffer contains the specific SOCKADDR structure type that corresponds to the address
family that the WSK application specified when it created the datagram socket.

## Remarks

The WSK subsystem passes a pointer to a WSK_DATAGRAM_INDICATION structure as the
*DataIndication* parameter when it calls a datagram socket's
[WskReceiveFromEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from_event) event callback
function.

## See also

[CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr)

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf)

[WskReceiveFromEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from_event)

[WskRelease](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff571144(v=vs.85))