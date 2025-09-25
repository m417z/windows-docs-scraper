# W_INITIATE_OFFLOAD_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

*MiniportInitiateOffload* offloads TCP chimney state from the host stack.

## Parameters

### `MiniportAdapterContext` [in]

The handle to an offload-target allocated context area in which the offload target maintains state
information about this instance of the adapter. The miniport driver provided this handle to NDIS when it
called
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `OffloadBlockList` [in, out]

A pointer to an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure that can be a stand-alone structure or the root of a
linked list of such structures.

## Remarks

The
*MiniportInitiateOffload* function stores the
*OffloadBlockList* pointer and then returns. The offload target always completes the offload
operation asynchronously by calling
[NdisMInitiateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisminitiateoffloadcomplete). The state tree pointed to by the
*OffloadBlockList* pointer is valid until the miniport driver calls
**NdisMInitiateOffloadComplete**.

After returning from its
*MiniportInitiateOffload* function, the offload target offloads state from the state tree. An
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure whose
**MiniportOffloadContext** member points to a memory location that contains a **NULL** value is followed by
state to be offloaded. For more information, see
[Storing and Referencing
Offloaded State](https://learn.microsoft.com/windows-hardware/drivers/network/storing-and-referencing-offloaded-state). The
**Header** member of an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure contains a
**Type** member that specifies the type of offload state, and by implication, the
[offload state structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated) or structures,
that immediately follow the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure in memory.

The offload target offloads the offload state associated with an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST
structure into an offload context area. For more information, see
[Storing and Referencing
Offloaded State](https://learn.microsoft.com/windows-hardware/drivers/network/storing-and-referencing-offloaded-state).

When offloading state, the offload target must traverse the state tree in
[depth-first/breadth-next fashion](https://learn.microsoft.com/windows-hardware/drivers/network/traversing-a-state-tree). It
is critical that an offload target offloads state in this way.

Some of the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structures in the state tree that are passed to the
*MiniportInitiateOffload* function can be placeholders or linking nodes that do not have accompanying
state to be offloaded. For more information, see
[Placeholders, Linkers, and
New Offloads](https://learn.microsoft.com/windows-hardware/drivers/network/placeholders--linkers--and-new-offloads).

The offload target can receive buffered data from the host stack for a connection that is being
offloaded. The offload target must copy this data into its own buffer before completing the offload
operation. For more information about processing buffered receive data, see
[Handling Buffered Receive Data During and After an Offload Operation](https://learn.microsoft.com/windows-hardware/drivers/network/handling-buffered-receive-data-during-and-after-an-offload-operation).

For each state object that it offloads, the offload target must also supply a PVOID value that
references the offload context area in which the offload target stores the state object. The offload
target writes this PVOID value to the memory location pointed to by the
***MiniportOffloadContext** member of the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure associated with
the state. If the offload target did not successfully offload the state associated with the
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure, it should not write a value to the memory location pointed to
by the
***MiniportOffloadContext** member. For more information, see
[Storing and Referencing
Offloaded State](https://learn.microsoft.com/windows-hardware/drivers/network/storing-and-referencing-offloaded-state).

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NdisMInitiateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisminitiateoffloadcomplete)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)