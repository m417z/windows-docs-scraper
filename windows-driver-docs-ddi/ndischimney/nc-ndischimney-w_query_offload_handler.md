# W_QUERY_OFFLOAD_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The
*MiniportQueryOffload* function queries previously offloaded TCP chimney state objects.

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
structures. These structures identify the offloaded state that is being queried.

## Remarks

The
*MiniportQueryOffload* function can query any TCP chimney state that has been offloaded to the
offload target.

The
*MiniportQueryOffload* function stores the
*OffloadBlockList* pointer and then returns. The offload target always completes the query operation
asynchronously by calling the
[NdisMQueryOffloadStateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismqueryoffloadstatecomplete) function. The
*OffloadBlockList* pointer points to an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure that can either be a stand-alone structure or the root
node in an
[offload state tree](https://learn.microsoft.com/windows-hardware/drivers/network/offload-state-tree). The state tree is valid
until the offload target calls the
**NdisMQueryOffloadStateComplete** function.

After returning from the
*MiniportQueryOffload* function, the miniport driver fills in the
[offload state structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated) that is
associated with each NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure in the state tree pointed to by the
*OffloadBlockList* pointer. To each of these offload state structures, the miniport driver writes the
current value of each variable in the structure.

Before calling the
**NdisMQueryOffloadStateComplete** function, the offload target must write either of the following
NDIS_STATUS values to the
**Status** member of each NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure in the state tree:

* NDIS_STATUS_SUCCESS

  The offload target successfully queried the state objects.
* NDIS_STATUS_FAILURE

  The query operation did not succeed. The host stack will terminate the state objects that could not
  be queried.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NdisMQueryOffloadStateComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndismqueryoffloadstatecomplete)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)