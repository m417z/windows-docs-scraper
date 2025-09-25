# _WSK_DATA_INDICATION structure

## Description

The WSK_DATA_INDICATION structure describes data that has been received on a connection-oriented
socket.

## Members

### `Next`

A pointer to the next WSK_DATA_INDICATION structure in a linked list of WSK_DATA_INDICATION
structures. If this member is **NULL**, this structure is the last WSK_DATA_INDICATION structure in the
linked list.

### `Buffer`

A WSK_BUF structure that describes the data that has been received on the socket.

## Remarks

The WSK subsystem passes a pointer to a WSK_DATA_INDICATION structure as the
*DataIndication* parameter when it calls a connection-oriented socket's
[WskReceiveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_event) event callback
function.

## See also

[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf)

[WskReceiveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_event)

[WskRelease](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff571144(v=vs.85))