# W_UPDATE_OFFLOAD_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The
*MiniportUpdateOffload* function updates previously offloaded TCP chimney state objects.

## Parameters

### `MiniportAdapterContext` [in]

The handle to an offload target-allocated context area in which the offload target maintains state
information about this instance of the adapter. The offload target provided this handle to NDIS when it
called
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `OffloadBlockList` [in]

A pointer to an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure, which can be the root of a linked list of such
structures. These structures identify the offloaded state objects that are being updated. Only cached
variables are updated.

## Remarks

Only cached variables are updated.

The
*MiniportUpdateOffload* function stores the
*MiniportAdapterContext* handle and the
*OffloadBlockList* pointer and then returns. The offload target always completes the update operation
asynchronously by calling the
[NdisMUpdateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismupdateoffloadcomplete) function. The
*OffloadBlockList* pointer points to an NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure that can either be
a stand-alone structure or the root block list in an
[offload state tree](https://learn.microsoft.com/windows-hardware/drivers/network/offload-state-tree) that contains multiple
NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structures. Such block lists, as well as any
[offload state structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated) that are
associated with them, are valid until the miniport driver calls the
**NdisMUpdateOffloadComplete** function.

Before the
*MiniportUpdateOffload* function returns, the offload target uses the offload state tree passed to
the
*MiniportUpdateOffload* function to update offloaded state:

* The offload target copies the variable values from any state structures in the tree to the
  corresponding
  [offloaded state objects](https://learn.microsoft.com/windows-hardware/drivers/network/offload-state-objects). Only CACHED
  variables are updated.
* The tree might indicate that path-to-neighbor links must be updated. For more information, see
  [Linking
  Path State Objects to a New Neighbor State Object](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler). In this case, the offload target must update
  its internal representation of offloaded state to reflect the updated links.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisMUpdateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismupdateoffloadcomplete)