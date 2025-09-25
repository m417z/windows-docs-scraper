# NdisMIndicateReceiveNetBufferLists function

## Description

Miniport drivers call the
**NdisMIndicateReceiveNetBufferLists** function to indicate the receipt of data from the network.

## Parameters

### `MiniportAdapterHandle` [in]

The miniport handle that NDIS passed to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `NetBufferList`

A linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that the
miniport driver allocated.

### `PortNumber` [in]

A port number that identifies a miniport adapter port. To assign a miniport adapter port number,
call the
[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport) function. A zero
value identifies the default port of a miniport adapter. Use the default port if the miniport driver has
not allocated ports for the specified adapter.

### `NumberOfNetBufferLists` [in]

The number of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are in the linked list of structures at
*NetBufferLists* .

### `ReceiveFlags` [in]

Flags that define attributes for the send operation. The flags can be combined with an OR
operation. To clear all the flags, set this member to zero. This function supports the following flags:

#### NDIS_RECEIVE_FLAGS_DISPATCH_LEVEL

Specifies that the current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_RECEIVE_FLAGS_RESOURCES

Specifies that the miniport driver reclaims ownership of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures and any
attached [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures immediately after the call to
**NdisMIndicateReceiveNetBufferLists** returns.

#### NDIS_RECEIVE_FLAGS_SINGLE_ETHER_TYPE

Specifies that all of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at *NetBufferLists* have the same protocol type (EtherType).

**Miniport drivers**

NDIS_RECEIVE_FLAGS_SINGLE_ETHER_TYPE is optionally set by miniport drivers that are certain all NBLs in an NBL chain have the same EtherType. By setting this flag, the miniport driver informs NDIS and upper layer protocols that they do not have to examine each packet for its EtherType, which increases performance. Miniport drivers are never required to set this flag.

**Light-weight filters (LWFs)**

When indicating novel receives, a light-weight filter (LWF) can also optionally set NDIS_RECEIVE_FLAGS_SINGLE_ETHER_TYPE if it is certain that all NBLs in an NBL chain have the same EtherType. However, like miniport drivers, LWFs are never required to set this flag in this case, and can always choose to clear the flag.

When passing through receives from the lower layer, if a LWF changes the EtherType of the NBLs, the LWF **must** clear the flag if the NBLs no longer have the same EtherType.

When passing through receives from the lower layer, if a LWF changes the EtherType of the NBLs, the LWF can set optionally set this flag if it is certain that all NBLs in an NBL chain have the same EtherType. In this case, the LWF is never required to set this flag and can always choose to clear it.

When consuming receives from the lower layer, if this flag is set, a LWF can assume that each NBL in the chain has the same EtherType. The LWF is never required to read this flag and can instead choose to always read the EtherType from every NBL.

When combining multiple NBL chains, a LWF **must** clear this flag unless it is certain that the new NBL chain has a homogenous EtherType.

**Protocol drivers**

When consuming receives from the lower layer, if NDIS_RECEIVE_FLAGS_SINGLE_ETHER_TYPE is set, the protocol can assume that each NBL in the chain has the same EtherType. A protocol is never required to read this flag and can instead choose to always read the EtherType from every NBL.

#### NDIS_RECEIVE_FLAGS_SINGLE_VLAN

Specifies that all of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
*NetBufferLists* belong to the same VLAN.

#### NDIS_RECEIVE_FLAGS_PERFECT_FILTERED

Specifies that all of the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the list at
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

## Remarks

A miniport driver typically calls the
**NdisMIndicateReceiveNetBufferLists** function from its
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) function.
When a miniport driver calls
**NdisMIndicateReceiveNetBufferLists**, it specifies a list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in the
*NetBufferLists* parameter. NDIS passes the **NET_BUFFER_LIST** structures to the
[ProtocolReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_receive_net_buffer_lists) function of bound protocol drivers.

Miniport drivers must set the
**SourceHandle** member of each [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure to the same value as the
*MiniportAdapterHandle* parameter.

If a miniport driver calls
**NdisMIndicateReceiveNetBufferLists** and clears the **NDIS_RECEIVE_FLAG_RESOURCES** flag in the
*ReceiveFlags* parameter, NDIS returns the indicated [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures to the miniport
driver's
[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists) function. In this case, the miniport driver must not reclaim the
**NET_BUFFER_LIST** structures until NDIS returns the **NET_BUFFER_LIST** structures to the miniport driver's
*MiniportReturnNetBufferLists* function.

If a miniport driver calls
**NdisMIndicateReceiveNetBufferLists** and sets the **NDIS_RECEIVE_FLAG_RESOURCES** flag in the
*ReceiveFlags* parameter, this indicates that the miniport driver must regain ownership of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures immediately. In this case, NDIS does not call the miniport driver's
*MiniportReturnNetBufferLists* function to return the **NET_BUFFER_LIST** structures. Instead, NDIS
returns the **NET_BUFFER_LIST** structures to the miniport driver upon return from
**NdisMIndicateReceiveNetBufferLists**. The miniport driver should reclaim the **NET_BUFFER_LIST**
structures immediately after
**NdisMIndicateReceiveNetBufferLists** returns. To reclaim the **NET_BUFFER_LIST** structures, a miniport
driver can call its own
[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists) function.

Setting the **NDIS_RECEIVE_FLAG_RESOURCES** flag in the
*ReceiveFlags* parameter forces the protocol drivers to copy the network data and release the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures to the miniport driver. Driver writers should design their miniport drivers
with enough preallocated **NET_BUFFER_LIST** structures to avoid unnecessary copying.

The caller of
**NdisMIndicateReceiveNetBufferLists** must properly initialize the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures,
attached
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures, and any attached MDLs.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists)

[NDIS_RECEIVE_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_parameters)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport)

[ProtocolReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_receive_net_buffer_lists)