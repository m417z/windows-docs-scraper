# NdisReturnNetBufferLists function

## Description

NDIS drivers call the
**NdisReturnNetBufferLists** function to release ownership of a list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures, along with the
associated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures and network data.

## Parameters

### `NdisBindingHandle` [in]

A handle that identifies the target adapter. This handle was returned by a previous call to the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function. All of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are
specified in this call must be from the binding that this handle identifies.

### `NetBufferLists` [in]

A pointer to a linked list of NET_BUFFER_LIST structures that are to be returned to the underlying
driver. The linked list can contain NET_BUFFER_LIST structures from multiple previous calls to the
[ProtocolReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_receive_net_buffer_lists) function.

### `ReturnFlags` [in]

NDIS flags that can be combined with an OR operation. To clear all the flags, set this member to
zero. This function supports the NDIS_RETURN_FLAGS_DISPATCH_LEVEL flag which; if set, indicates that the
current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

## Remarks

If the NDIS_RECEIVE_FLAGS_RESOURCES flag in the
*ReceiveFlags* parameter that NDIS passed to the
[ProtocolReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_receive_net_buffer_lists) function was not set, the protocol driver must call
**NdisReturnNetBufferLists** to return the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and associated
data. After the protocol driver calls
**NdisReturnNetBufferLists**, NDIS calls the underlying miniport driver's
[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists) function.

## See also

[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_receive_net_buffer_lists)