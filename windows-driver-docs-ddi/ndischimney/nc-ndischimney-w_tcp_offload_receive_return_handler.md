# W_TCP_OFFLOAD_RECEIVE_RETURN_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

NDIS calls the
*MiniportTcpOffloadReceiveReturn* function to return ownership of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) and associated structures to
an offload target.

## Parameters

### `MiniportAdapterContext` [in]

The handle to an offload-target allocated context area in which the offload target maintains state
information about this instance of the adapter. The miniport driver provided this handle to NDIS when it
called
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This structure
can be a stand-alone structure or the first structure in a linked list of NET_BUFFER_LIST structures.
The linked list can contain NET_BUFFER_LIST structures from one or more calls to the
[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate) function.

## Return value

The
*MiniportTcpOffloadReceiveReturn* function should always succeed. Therefore, the
*MiniportTcpOffloadReceiveReturn* function should always return NDIS_STATUS_SUCCESS.

## Remarks

NDIS calls the
*MiniportTcpOffloadReceiveReturn* function to return ownership of NET_BUFFER_LIST structures and
associated structures that the offload target passed in one or more previous calls to the
[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate) function.

The
*MiniportTcpOffloadReceiveReturn* function can prepare a returned NET_BUFFER_LIST structure for use
in a subsequent receive indication. Although the
*MiniportTcpOffloadReceiveReturn* function can return the NET_BUFFER_LIST structures to a pool (for
example, it could call the
[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist) function), it
can be more efficient to reuse the structures without returning them to the pool.

Note that the offload target driver should not unload and the offload target adapter must not be
closed until all indicated receive buffers have been returned.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisFreeNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlist)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate)