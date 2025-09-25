# NdisFreeScatterGatherList function

## Description

The
**NdisFreeScatterGatherList** function frees a scatter/gather list.

## Parameters

### `NdisHandle` [in]

An NDIS driver or instance handle that was obtained during caller initialization. This should be
the same handle that was passed to the
[NdisBuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisbuildscattergatherlist) function when the scatter/gather list was created.

### `ScatterGatherListBuffer` [in]

A pointer to a caller-provided
[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure to free.
This must be the same buffer that was passed to the
**NdisBuildScatterGatherList** function when the scatter/gather list was allocated.

### `WriteToDevice` [in]

A BOOLEAN value that is set to **TRUE** if the scatter/gather list was used for writing to the device.
Otherwise, it is **FALSE**.

## Remarks

NDIS drivers call the
**NdisFreeScatterGatherList** function to free a scatter/gather list that was created with the
[NdisBuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisbuildscattergatherlist) function.

## See also

[NdisBuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisbuildscattergatherlist)

[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list)