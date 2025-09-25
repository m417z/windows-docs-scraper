# NdisFIndicateReceiveNetBufferLists function

## Description

A filter driver calls
**NdisFIndicateReceiveNetBufferLists** to indicate that it has received network data. For more information, see [Receiving Data in a Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/network/receiving-data-in-a-filter-driver).

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetBufferLists` [in]

A linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. Each
**NET_BUFFER_LIST** structure contains one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

### `PortNumber` [in]

A port number that identifies a miniport adapter port. Miniport adapter port numbers are assigned
by calling the
[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport) function. A zero
value identifies the default port of a miniport adapter.

### `NumberOfNetBufferLists` [in]

The number of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are in the linked list of structures at
*NetBufferLists* .

### `ReceiveFlags` [in]

Flags that define attributes for the receive indication. The flags can be combined with an OR
operation. To clear all the flags, set this member to zero. This function supports the following flags:

#### NDIS_RECEIVE_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is **DISPATCH_LEVEL**. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_RECEIVE_FLAGS_RESOURCES

Specifies that the filter driver reclaims ownership of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and any
attached [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures immediately after the call to
**NdisFIndicateReceiveNetBufferLists** returns.

#### NDIS_RECEIVE_FLAGS_SINGLE_ETHER_TYPE

Specifies that all the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* have the same protocol type (EtherType).

#### NDIS_RECEIVE_FLAGS_SINGLE_VLAN

Specifies that all the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* belong to the same VLAN.

#### NDIS_RECEIVE_FLAGS_PERFECT_FILTERED

Specifies that all the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* include only data that matches the packet filter and multicast address list that are
assigned to the miniport adapter.

#### NDIS_RECEIVE_FLAGS_SINGLE_QUEUE

Specifies that all the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* belong to the same VM queue. A miniport driver must set this flag for all receive
indications on a queue if the **NDIS_RECEIVE_QUEUE_PARAMETERS_PER_QUEUE_RECEIVE_INDICATION** flag was set
in the
**Flags** member of the
[NDIS_RECEIVE_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_parameters) structure when that queue was allocated.

#### NDIS_RECEIVE_FLAGS_SHARED_MEMORY_INFO_VALID

Specifies that all the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* contain shared memory information that is valid. When this flag is set on a
received **NET_BUFFER_LIST**, NDIS treats the shared memory information as valid. When this flag is not
set, NDIS and drivers ignore the shared memory information. For example, intermediate drivers that
modify packet data can use this flag to determine if data should be copied. Miniport drivers can use
the flag to determine how to free the memory that is associated with a VM queue when a queue is
deleted.

#### NDIS_RECEIVE_FLAGS_MORE_NBLS

Reserved.

#### NDIS_RECEIVE_FLAGS_SWITCH_SINGLE_SOURCE

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures originated from the same Hyper-V extensible switch source port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

**Note** If each packet in the linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures uses the same source port, the extension should set the **NDIS_RETURN_FLAGS_SWITCH_SINGLE_SOURCE** flag in the *ReturnFlags* parameter of [FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists) when the receive request completes. The extension must set this flag in the *ReturnFlags* parameter if it calls [NdisFReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreturnnetbufferlists) to return packets that it did not originate or clone.

#### NDIS_RECEIVE_FLAGS_SWITCH_DESTINATION_GROUP

If this flag is set, all packets in a linked list of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures are to be forwarded to the same extensible switch destination port.

For more information, see [Hyper-V Extensible Switch Send and Receive Flags](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-send-and-receive-flags).

## Remarks

When a filter driver calls the
**NdisFIndicateReceiveNetBufferLists** function, it specifies a list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the
*NetBufferLists* parameter. NDIS passes the **NET_BUFFER_LIST** structures to the overlying drivers.

Filter drivers can call
**NdisFIndicateReceiveNetBufferLists** to originate a receive indication.

Filter drivers can also filter receive indications that are originated by underlying drivers. NDIS
calls the
[FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists) function to filter such receive indications.

A filter driver must set the
**SourceHandle** member of each [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that it originates to the same value as the
*NdisFilterHandle* parameter. The filter driver must not modify the
**SourceHandle** member in any **NET_BUFFER_LIST** structures that it did not originate.

The filter driver must properly initialize the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures, attached
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures, and any attached MDLs.

If a filter driver calls the
**NdisFIndicateReceiveNetBufferLists** function and clears the **NDIS_RECEIVE_FLAG_RESOURCES** flag in the
*ReceiveFlags* parameter, NDIS returns the indicated [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures to the filter
driver's
[FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists) function. In this case, the filter driver must not reclaim the
**NET_BUFFER_LIST** structures until NDIS returns the **NET_BUFFER_LIST** structures to
*FilterReturnNetBufferLists*.

If a filter driver calls
**NdisFIndicateReceiveNetBufferLists** and sets the **NDIS_RECEIVE_FLAG_RESOURCES** flag in the
*ReceiveFlags* parameter, this indicates that the filter driver must regain ownership of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures immediately. In this case, NDIS does not call the filter driver's
[FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists) function to return the **NET_BUFFER_LIST** structures. Instead, NDIS returns
the **NET_BUFFER_LIST** structures to the filter driver upon return from
**NdisFIndicateReceiveNetBufferLists**. The filter driver should reclaim the **NET_BUFFER_LIST**
structures immediately after
**NdisFIndicateReceiveNetBufferLists** returns. To reclaim the **NET_BUFFER_LIST** structures, a filter
driver can call its own
*FilterReturnNetBufferLists* function.

Setting the **NDIS_RECEIVE_FLAG_RESOURCES** flag in the
*ReceiveFlags* parameter forces the overlying drivers to copy the network data and release the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures to the filter driver.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists)

[FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists)

[NDIS_RECEIVE_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_parameters)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport)

[Receiving Data in a Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/network/receiving-data-in-a-filter-driver)