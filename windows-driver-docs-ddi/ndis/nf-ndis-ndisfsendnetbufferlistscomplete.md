# NdisFSendNetBufferListsComplete function

## Description

Filter drivers call the
**NdisFSendNetBufferListsComplete** function to return a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures to an overlying
driver and to return the final status of a send request.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetBufferList`

A pointer to a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. The filter driver received the
**NET_BUFFER_LIST** structures in previous calls to the
[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists) function.

### `SendCompleteFlags` [in]

NDIS flags that can be combined with an OR operation. To clear all the flags, set this member to zero. This function supports the following flags:

#### NDIS_SEND_COMPLETE_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_SEND_COMPLETE_FLAGS_SWITCH_SINGLE_SOURCE

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures originated from the same Hyper-V extensible switch source port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

**Note** If each packet in the linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures uses the same source port, the extension should set the **NDIS_SEND_FLAGS_SWITCH_SINGLE_SOURCE** flag in the *SendFlags* parameter of [NdisFSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlists) when it sends the request.

**Note** This flag is available in NDIS 6.30 and later.

## Remarks

A filter driver calls the
**NdisFSendNetBufferListsComplete** function to complete send requests that NDIS made to the driver's
[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists) function. The filter driver specifies a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are
associated with the completed send requests. While the status of the send requests is pending, the filter
driver retains ownership of the **NET_BUFFER_LIST** structures and all the resources that are associated with
the **NET_BUFFER_LIST** structures.

The filter driver can complete send requests in any order. For example, the filter driver could
concatenate the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure lists from multiple
[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists) calls or split up a list from a
*FilterSendNetBufferLists* call. However, the filter driver must not modify the list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures that are associated with a
**NET_BUFFER_LIST** structure.

**Note** A filter driver should keep track of send requests that it originates and make
sure that it does not call the
**NdisFSendNetBufferListsComplete** function when such requests are complete.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)