# W_TERMINATE_OFFLOAD_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The
*MiniportTerminateOffload* function terminates the offload of one or more state objects.

## Parameters

### `MiniportAdapterContext` [in]

The handle to an offload-target allocated context area in which the offload target maintains state
information about this instance of the adapter. The offload target provided this handle to NDIS when it
called
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `OffloadBlockList` [in, out]

A pointer to an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure, which can be the root of a linked list of such
structures. These structures identify the offloaded state objects that are being terminated.

## Remarks

The
*MiniportTerminateOffload* function stores the
*OffloadBlockList* pointer and then returns. The offload target always completes the terminate
operation asynchronously by calling the
[NdisMTerminateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismterminateoffloadcomplete) function.

The
*OffloadBlockList* pointer points to an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure that can be either
a stand-alone structure or the root block list in an
[offload state tree](https://learn.microsoft.com/windows-hardware/drivers/network/offload-state-tree) that contains multiple
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structures. Such block lists, as well as any
[offload state structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated) that are
associated with them, are valid until the miniport driver calls the
**NdisMTerminateOffloadComplete** function.

Each NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure can be immediately followed in memory by a delegated
state structure (*XXX*_OFFLOAD_STATE_DELEGATED). The offload target copies delegated variable values into the
delegated state structures supplied by the host stack.

The host stack will not request the termination of the offload of a TCP connection until both of the
following conditions are met:

* All the outstanding invalidate, query, and update requests pertaining to that connection have
  completed.
* All outstanding receive and disconnect calls have returned.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisMTerminateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismterminateoffloadcomplete)

[TCP_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated)