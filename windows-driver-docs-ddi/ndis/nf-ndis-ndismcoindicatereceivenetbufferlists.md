# NdisMCoIndicateReceiveNetBufferLists function

## Description

The
**NdisMCoIndicateReceiveNetBufferLists** function indicates that the miniport driver received data from
the network.

## Parameters

### `NdisVcHandle` [in]

A handle that identifies a virtual connection (VC). The miniport driver obtained this handle as an
input parameter to its
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) function, either
when a client set up an outgoing call or when the call manager created a VC for a client-registered
service access point (SAP) to indicate an incoming-call notification on.

### `NetBufferLists` [in]

A linked list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that the
miniport driver allocated.

### `NumberOfNetBufferLists` [in]

The number of NET_BUFFER_LIST structures that are in the linked list of structures that
*NetBufferLists* specifies.

### `CoReceiveFlags` [in]

Flags that define attributes for the send operation. The flags can be combined with a bitwise OR
operation. To clear all of the flags, set this parameter to zero.
**NdisMCoIndicateReceiveNetBufferLists** supports the following flags:

#### NDIS_RECEIVE_FLAGS_DISPATCH_LEVEL

The current IRQL is DISPATCH_LEVEL. For more information about this flag, see
[Dispatch IRQL Tracking](https://learn.microsoft.com/windows-hardware/drivers/network/dispatch-irql-tracking).

#### NDIS_RECEIVE_FLAGS_RESOURCES

The miniport driver reclaims ownership of the NET_BUFFER_LIST structures and any attached
NET_BUFFER structures immediately after
**NdisMCoIndicateReceiveNetBufferLists** returns.

## Remarks

A miniport driver typically calls the
**NdisMCoIndicateReceiveNetBufferLists** function from its
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) function.
When a miniport driver calls
**NdisMCoIndicateReceiveNetBufferLists**, it specifies a list of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures at the
*NetBufferLists* parameter. NDIS then passes the NET_BUFFER_LIST structures to bound protocol drivers.

Miniport drivers must set the
**SourceHandle** member of each NET_BUFFER_LIST structure to the same value as the
*NdisVcHandle* parameter so that NDIS can return the NET_BUFFER_LIST structures to the correct
miniport driver.

If a miniport driver calls
**NdisMCoIndicateReceiveNetBufferLists** and clears the NDIS_RECEIVE_FLAGS_RESOURCES flag in the
*CoReceiveFlags* parameter, NDIS returns the NET_BUFFER_LIST structures that
*NetBufferLists* specifies to the miniport driver's
[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists) function. In this case, the miniport driver must not reclaim the
NET_BUFFER_LIST structures until NDIS returns the NET_BUFFER_LIST structures to the miniport driver's
*MiniportReturnNetBufferLists* function.

If a miniport driver calls
**NdisMCoIndicateReceiveNetBufferLists** and sets the NDIS_RECEIVE_FLAGS_RESOURCES flag in the
*CoReceiveFlags* parameter, the miniport driver must regain ownership of the NET_BUFFER_LIST
structures immediately. In this case, NDIS does not call the miniport driver's
*MiniportReturnNetBufferLists* function to return the NET_BUFFER_LIST structures. Instead, NDIS
returns the NET_BUFFER_LIST structures to the miniport driver when
**NdisMCoIndicateReceiveNetBufferLists** returns. The miniport driver should reclaim the
NET_BUFFER_LIST structures immediately after
**NdisMCoIndicateReceiveNetBufferLists** returns. To reclaim the NET_BUFFER_LIST structures, a miniport
driver can call its own
[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists) function.

If a miniport driver sets the NDIS_RECEIVE_FLAGS_RESOURCES flag in the
*CoReceiveFlags* parameter, the protocol drivers must copy the network data and release the
NET_BUFFER_LIST structures to the miniport driver. You should design your miniport drivers with enough
preallocated NET_BUFFER_LIST structures to avoid unnecessary copying.

The caller of
**NdisMCoIndicateReceiveNetBufferLists** must properly initialize the NET_BUFFER_LIST structures, the
attached
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures, and any attached memory
descriptor lists (MDLs).

## See also

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)