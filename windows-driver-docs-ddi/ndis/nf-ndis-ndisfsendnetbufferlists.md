# NdisFSendNetBufferLists function

## Description

Filter drivers call the
**NdisFSendNetBufferLists** function to send a list of network data buffers.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetBufferList`

A pointer to a linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. Each
**NET_BUFFER_LIST** structure describes a list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures.

### `PortNumber` [in]

A port number that identifies a miniport adapter port. Miniport adapter port numbers are assigned
by calling the
[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport) function. A zero
value identifies the default port of a miniport adapter.

### `SendFlags` [in]

Flags that define attributes for the send operation. The flags can be combined with an OR
operation. To clear all the flags, set this member to zero. This function supports the following flags:

#### NDIS_SEND_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_SEND_FLAGS_CHECK_FOR_LOOPBACK

Specifies that NDIS should check for loopback. By default, NDIS does not loop back data to the
driver that submitted the send request. An overlying driver can override this behavior by setting this
flag. When this flag is set, NDIS identifies all the [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures that contain data that
matches the receive criteria for the binding. NDIS indicates NET_BUFFER structures that match the
criteria to the overlying driver. This flag has no affect on checking for loopback, or looping back,
on other bindings.

#### NDIS_SEND_FLAGS_SWITCH_SINGLE_SOURCE

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures originated from the same Hyper-V extensible switch source port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

**Note** If each packet in the linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures uses the same source port, the extension should set the **NDIS_SEND_COMPLETE_FLAGS_SWITCH_SINGLE_SOURCE** flag in the *SendCompleteFlags* parameter of [NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) when it completes the send request.

**Note** This flag is available in NDIS 6.30 and later.

#### NDIS_SEND_FLAGS_SWITCH_DESTINATION_GROUP

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures are to be forwarded to the same extensible switch destination port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

**Note** This flag is available in NDIS 6.30 and later.

## Remarks

After a filter driver calls the
**NdisFSendNetBufferLists** function, NDIS submits the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures to the underlying
drivers.

A filter driver can originate send requests or it can filter the requests that it receives from
overlying drivers. If the filter driver originates send requests, the driver must allocate buffers pools.
The filter driver allocates each [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure from a pool.

The filter driver can preallocate [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures or it can allocate the structures just
before calling
**NdisFSendNetBufferLists** and then free them when the send operation is complete.

A filter driver must set the
**SourceHandle** member of each [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that it originates to the same value that it
passes to the
*NdisFilterHandle* parameter. The filter handle provides the information that NDIS requires to return
the **NET_BUFFER_LIST** structure to the filter driver. The filter driver must not modify the
**SourceHandle** member in any **NET_BUFFER_LIST** structures that it did not originate.

Before calling
**NdisFSendNetBufferLists**, a filter driver can set information that accompanies the send request
with the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro. The
underlying drivers can retrieve this information with the **NET_BUFFER_LIST_INFO** macro.

NDIS calls a filter driver's
[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists) function to pass on send requests from overlying drivers. A filter driver
can pass on such requests by passing the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)T structures that it received in
*FilterSendNetBufferLists* to
**NdisFSendNetBufferLists**.

As soon as a filter driver calls the
**NdisFSendNetBufferLists** function, it relinquishes ownership of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and
all associated resources. NDIS calls the
[FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete) function to return the structures and data to the filter driver.
NDIS can collect the structures and data from multiple send requests into a single linked list of
**NET_BUFFER_LIST** structures before it passes the list to
*FilterSendNetBufferListsComplete*.

Until NDIS calls
[FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete), the current status of the send request is not available to the
filter driver. A filter driver temporarily releases ownership of all resources that are associated with a
send request when it calls
**NdisFSendNetBufferLists**. A filter driver should never try to examine the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)
structures or any associated data after calling
**NdisFSendNetBufferLists**.

**Note** A filter driver should keep track of send requests that it originates and make
sure that it does not call the
[NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) function when such requests are complete.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists)

[FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport)