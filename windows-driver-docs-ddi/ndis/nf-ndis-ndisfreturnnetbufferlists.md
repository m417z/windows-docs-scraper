# NdisFReturnNetBufferLists function

## Description

Filter drivers call
**NdisFReturnNetBufferLists** to release the ownership of one or more
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and their
associated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetBufferLists` [in]

A pointer to a linked list of NET_BUFFER_LIST structures that are to be returned to the underlying
driver. The linked list can contain NET_BUFFER_LIST structures from multiple previous calls to the
[FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists) function.

### `ReturnFlags` [in]

NDIS flags that can be combined with an OR operation. To clear all the flags, set this member to
zero.This function supports the following flags:

#### NDIS_RETURN_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_RETURN_FLAGS_SWITCH_SINGLE_SOURCE

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures originated from the same Hyper-V extensible switch source port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

**Note** If each packet in the linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures uses the same source port, the extension should set the **NDIS_RECEIVE_FLAGS_SWITCH_SINGLE_SOURCE** flag in the *ReceiveFlags* parameter of [NdisFIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfindicatereceivenetbufferlists) when it sends the request.

## Remarks

If the NDIS_RECEIVE_FLAGS_RESOURCES flag in the
*ReceiveFlags* parameter that NDIS passed to the
[FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists) function was not set, the filter driver must call the
**NdisFReturnNetBufferLists** function to return the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and associated
data. After the filter driver calls
**NdisFReturnNetBufferLists**, NDIS returns the data to the underlying driver.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)