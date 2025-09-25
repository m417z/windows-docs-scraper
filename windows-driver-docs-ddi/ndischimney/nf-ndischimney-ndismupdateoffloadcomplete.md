# NdisMUpdateOffloadComplete function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

An offload target calls the
**NdisMUpdateOffloadComplete** function to complete an update offload operation that was initiated by a
previous call to the
[MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler) function of
the offload target.

## Parameters

### `NdisMiniportHandle` [in]

The handle that the offload target obtained in a previous call to
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver).

### `OffloadBlockList` [in]

A pointer to an
[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list) structure. The offload target obtained this pointer as an input
parameter to its
[MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler) function.

## Remarks

Before calling the
**NdisMUpdateOffloadComplete** function, the offload target must write either of the following
NDIS_STATUS values to the
**Status** member of each NDIS_MINIPORT_OFFLOAD_BLOCK_LIST structure in the state tree:

* NDIS_STATUS_SUCCESS

  The offload target successfully updated the state object variables and/or successfully updated
  path-to-neighbor links.
* NDIS_STATUS_FAILURE

  The update operation did not succeed. The offload target should continue normal processing on the
  connection. The host stack will terminate the offload of state objects that could not be updated.

## See also

[MiniportUpdateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_update_offload_handler)

[NDIS_MINIPORT_OFFLOAD_BLOCK_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_miniport_offload_block_list)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)