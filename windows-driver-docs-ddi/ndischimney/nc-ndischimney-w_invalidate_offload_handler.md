# W_INVALIDATE_OFFLOAD_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The
*MiniportInvalidateOffload* function invalidates previously offloaded TCP chimney state objects.

## Parameters

### `MiniportAdapterContext` [in]

The handle to an offload-target allocated context area in which the offload target maintains state
information about this instance of the adapter. The offload target provided this handle to NDIS when it
called
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `OffloadBlockList` [in]

A pointer to an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure, which can be the root of a linked list of such
structures. These structures identify the offloaded state object that is being invalidated.

## Remarks

The
*MiniportInvalidateOffload* function stores the
*OffloadBlockList* pointer and then returns. The offload target always completes the invalidate
operation asynchronously by calling
[NdisMInvalidateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisminvalidateoffloadcomplete).

The tree passed to the
*MiniportInvalidateOffload* function contains only NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structures. The
tree does not contain any
[offload state structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated). That is,
there are no such structures following the NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structures in memory.

The NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structures in the tree indicate the state object to be
invalidated. A non-NULL
***MiniportOffloadContext** member points to a memory location containing a PVOID value that was
supplied by the offload target when the state object was offloaded. For more information, see
[Storing and Referencing
Offloaded State](https://learn.microsoft.com/windows-hardware/drivers/network/storing-and-referencing-offloaded-state). This PVOID value references the miniport offload context in which the offload
target stores the state object to be invalidated.

For information about an offload target's treatment of invalidated state objects, see
[Treatment of Invalidated State
Objects](https://learn.microsoft.com/windows-hardware/drivers/network/handling-invalidated-state-objects).

Eventually, the host stack will
[terminate the offload of the invalidated
state object](https://learn.microsoft.com/windows-hardware/drivers/network/terminating-offload-state). However, until that time, the offload target owns the invalidated state object. The
offload target must not free the resources for the invalidated state object until the host stack has
terminated the offload of that state object. The offload target must not use the invalidated state object
or any TCP connections that depend on that state object for sending data.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NdisMInvalidateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisminvalidateoffloadcomplete)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)