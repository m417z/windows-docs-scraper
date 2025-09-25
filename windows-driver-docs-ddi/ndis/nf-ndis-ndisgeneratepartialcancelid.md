# NdisGeneratePartialCancelId function

## Description

The
**NdisGeneratePartialCancelId** function returns a value that the calling driver must use as the
high-order byte of a cancellation ID.

## Return value

**NdisGeneratePartialCancelId** returns a value that the calling driver uses as the high-order byte of
a cancellation ID.

## Remarks

Before marking send
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures with cancellation
IDs by calling the
[NDIS_SET_NET_BUFFER_LIST_CANCEL_ID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-set-net-buffer-list-cancel-id) macro, a driver should call
**NdisGeneratePartialCancelId** one or more times.
**NdisGeneratePartialCancelId** returns a value that the calling driver can use as the high-order byte
of a cancellation ID. Prefixing a cancellation ID with the value returned by
**NdisGeneratePartialCancelId** ensures that the cancellation ID will not be a duplicate of a
cancellation ID assigned by another driver in the local computer.

Typically, an overlying driver calls
**NdisGeneratePartialCancelId** one or more times during its initialization sequence and stores the
returned value or values for later use. A protocol driver, for example, could call
**NdisGeneratePartialCancelId** once for each client (such as DHCP or ARC) that it supports. The
protocol driver can call the
[NdisCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists) function later to cancel a send request. In this case, NDIS calls the
cancel send function (for example,
[MiniportCancelSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_send)) of the
underlying drivers.

## See also

[MiniportCancelSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_send)

[NDIS_SET_NET_BUFFER_LIST_CANCEL_ID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-set-net-buffer-list-cancel-id)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists)