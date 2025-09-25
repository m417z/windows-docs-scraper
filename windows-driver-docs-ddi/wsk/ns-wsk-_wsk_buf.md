# _WSK_BUF structure

## Description

The WSK_BUF structure defines a data buffer that is used for sending and receiving data over a
socket.

## Members

### `Mdl`

A pointer to a memory descriptor list (MDL). The MDL can be a single MDL or the first MDL in an
MDL chain. If the
**Length** member is zero, this pointer can be **NULL**.

### `Offset`

An offset to where the data starts in the MDL. If the
**Mdl** member points to the first MDL in an MDL chain, this offset must be within the memory buffer
that is described by the first MDL in the chain. If the
**Mdl** member is **NULL**, the
**Offset** member is not used.

### `Length`

When a WSK_BUF structure is used to describe a buffer of data to be sent over a socket, this
member specifies the number of bytes of data in the MDL (or MDL chain) to be sent.

When a WSK_BUF structure is used to describe a buffer for receiving data from a socket, this member
specifies the maximum number of bytes to be received into the MDL (or MDL chain).

When a WSK_BUF structure is contained within either a
[WSK_DATA_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_data_indication) structure or a
[WSK_DATAGRAM_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_datagram_indication) structure,
this member specifies the number of bytes of received data in the MDL (or MDL chain).

## Remarks

Each MDL in the MDL chain that is pointed to by the
**Mdl** member describes memory that is either locked or from non-paged pool.

When a WSK application passes a pointer to a WSK_BUF structure to the
[WskReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive) function, the application can
specify zero for the
**Length** member of the structure. In that situation, the
**Mdl** member can be **NULL** because no data will be copied into the buffer.

## See also

[WSK_DATAGRAM_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_datagram_indication)

[WSK_DATA_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_data_indication)

[WskDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect)

[WskReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive)

[WskReceiveFrom](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from)

[WskSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send)

[WskSendTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send_to)