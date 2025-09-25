# NdisMCoSendNetBufferListsComplete function

## Description

The
**NdisMCoSendNetBufferListsComplete** function returns a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures to an overlying
driver and returns the final status of a CoNDIS send request.

## Parameters

### `NdisVcHandle` [in]

A handle that identifies a virtual connection (VC). The miniport driver obtained this handle as an
input parameter to its
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) function, either
when a client set up an outgoing call or when the call manager created a VC for a client-registered
service access point (SAP) to indicate an incoming-call notification on.

### `NetBufferLists` [in]

A pointer to a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. The miniport
driver received the NET_BUFFER_LIST structures in previous calls to its
[MiniportCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_send_net_buffer_lists) function.

### `SendCompleteFlags` [in]

NDIS flags that can be combined with a bitwise OR operation. To clear all of the flags, set this
parameter to zero.
**NdisMCoSendNetBufferListsComplete** supports the NDIS_SEND_COMPLETE_FLAGS_DISPATCH_LEVEL flag,
which; if set, indicates that the current IRQL is DISPATCH_LEVEL. For more information about this flag,
see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

## Remarks

A miniport driver calls
**NdisMCoSendNetBufferListsComplete** to complete send requests that NDIS made to the driver's
[MiniportCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_send_net_buffer_lists) function. The miniport driver specifies a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are
associated with the completed send requests.

While the status of the send requests is pending, the miniport driver retains ownership of the
NET_BUFFER_LIST structures and all of the resources that are associated with the NET_BUFFER_LIST
structures.

After a miniport driver calls
**NdisMCoSendNetBufferListsComplete**, NDIS returns the NET_BUFFER_LIST structures and associated data
to the overlying driver that originated the send request.

The miniport driver can complete send requests in any order. For example, the miniport driver could
concatenate the NET_BUFFER_LIST structure lists from multiple
*MiniportCoSendNetBufferLists* calls or split up a list from a
*MiniportCoSendNetBufferLists* call. However, the miniport driver must not modify the list of
NET_BUFFER structures that are associated with a NET_BUFFER_LIST structure.

The miniport driver must set one of the following status codes in the
**Status** member of each NET_BUFFER_LIST structure that the
*NetBufferLists* parameter specifies:

A miniport driver's call to
**NdisMCoSendNetBufferListsComplete** does not necessarily indicate that the data for a send request
has been transmitted over the network. For example, the data might be queued in the NIC hardware.

## See also

[MiniportCancelSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_send)

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)

[MiniportCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_send_net_buffer_lists)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)