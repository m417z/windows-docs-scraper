# NdisMSendNetBufferListsComplete function

## Description

Miniport drivers call the
**NdisMSendNetBufferListsComplete** function to return a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures to an overlying driver and to return the final status of a send request.

## Parameters

### `MiniportAdapterHandle` [in]

The miniport handle that NDIS passed to the [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `NetBufferList`

A pointer to a linked list of NET_BUFFER_LIST structures. The miniport driver received the NET_BUFFER_LIST structures in previous calls to its [MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists) function.

### `SendCompleteFlags` [in]

NDIS flags that can be combined with an OR operation. To clear all the flags, set this member to zero. This function supports the NDIS_SEND_COMPLETE_FLAGS_DISPATCH_LEVEL flag which; if set, indicates that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see [Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

## Remarks

A miniport driver calls **NdisMSendNetBufferListsComplete** to complete send requests that NDIS made to the driver's
[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists) function. The miniport driver specifies a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are
associated with the completed send requests. While the status of the send requests is pending, the miniport driver retains ownership of the NET_BUFFER_LIST structures and all the protocol-allocated resources that are associated with the NET_BUFFER_LIST structures.

After a miniport driver calls **NdisMSendNetBufferListsComplete**, NDIS calls the
[ProtocolSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_send_net_buffer_lists_complete) function of the driver that called the [NdisSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissendnetbufferlists) function to initiate the send request.

The miniport driver can complete send requests in any order. For example, the miniport driver could concatenate the NET_BUFFER_LIST structure lists from multiple *MiniportSendNetBufferLists* calls or split up a list from a *MiniportSendNetBufferLists* call. However, the miniport driver must not modify the list of [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures that are associated with a
NET_BUFFER_LIST structure.

The miniport driver must set one of the following status codes in the **Status** member of each NET_BUFFER_LIST structure that the *NetBufferLists* parameter specifies:

|Structure|Description|
|----|----|
|NDIS_STATUS_SUCCESS|All the network data that the NET_BUFFER_LIST structure and the associated NET_BUFFER structures describe was successfully processed for transmission. For example, the miniport driver copied the data to a queue or the data has already been transmitted.|
|NDIS_STATUS_INVALID_LENGTH|The size of the data in some NET_BUFFER structures associated with this NET_BUFFER_LIST structure was too large for the underlying NIC.|
|NDIS_STATUS_RESOURCES|The send request for this NET_BUFFER_LIST structure failed due to insufficient resources.|
|NDIS_STATUS_PAUSED|The miniport adapter is in the Paused state, as described on the reference page for the MiniportPause function.|
|NDIS_STATUS_SEND_ABORTED|NDIS called the MiniportCancelSend function to cancel the send operation for this NET_BUFFER_LIST structure.|
|NDIS_STATUS_RESET_IN_PROGRESS|The miniport driver aborted the send request due to a reset.|
|NDIS_STATUS_FAILURE|The miniport driver failed the send request because of some reason other than those previously described. For example, the miniport driver can fail the send request due to a hardware failure.|

A miniport driver's call to
**NdisMSendNetBufferListsComplete** does not necessarily mean that the data for a send request has been transmitted over the network. The data might be queued in the NIC hardware.

## See also

[MiniportCancelSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_send)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)