# NdisMInvalidateOffloadComplete function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

An offload target calls the
**NdisMInvalidateOffloadComplete** function to complete an invalidate offload operation that was
initiated by a previous call to the
[MiniportInvalidateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_invalidate_offload_handler) function of the offload target.

## Parameters

### `NdisMiniportHandle` [in]

The handle that the offload target obtained in a previous call to the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

### `OffloadBlockList` [in]

A pointer to an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure. The offload target obtained this pointer as an input
parameter to its
[MiniportInvalidateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_invalidate_offload_handler) function.

## Remarks

Before calling the
**NdisMInvalidateOffloadComplete** function, the offload target must write either of the following
NDIS_STATUS values to the
**Status** member of each NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure in the state tree:

* NDIS_STATUS_SUCCESS

  The offload target successfully invalidated the state objects.
* NDIS_STATUS_FAILURE

  The invalidate operation did not succeed. In this case, the offload target has stopped responding (is
  hung).

## See also

[MiniportInvalidateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_invalidate_offload_handler)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)