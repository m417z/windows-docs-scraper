# NdisMQueryOffloadStateComplete function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

An offload target calls the
**NdisMQueryOffloadStateComplete** function to complete a query offload operation that was initiated by a
previous call to the offload target's
[MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler) function.

## Parameters

### `NdisMiniportHandle` [in]

The handle that the offload driver obtained in a previous call to
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver).

### `OffloadBlockList` [in]

A pointer to an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure. The offload target obtained this pointer as an input
parameter to its
[MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler) function.

## Remarks

An offload target calls
**NdisMQueryOffloadStateComplete** to complete a query operation that was initiated when NDIS called
the
[MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler) function of
the offload target.

Before calling
**NdisMQueryOffloadStateComplete**, the offload target must:

* Fill in each
  [offload state structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_delegated) in the state
  tree with the current values of that structure's variables.
* Write a status value of NDIS_STATUS_SUCCESS or NDIS_STATUS_FAILURE to the
  **Status** member of each NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure in the state tree.

## See also

[MiniportQueryOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_query_offload_handler)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)