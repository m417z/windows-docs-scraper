# NDIS_PROCESS_SG_LIST callback function

## Description

The
*NetProcessSGList* function (NDIS_PROCESS_SG_LIST_HANDLER entry point) processes a scatter/gather
list.

## Parameters

### `DeviceObject` [in]

A pointer to a
[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

### `Reserved` [in]

Reserved for NDIS.

### `ScatterGatherListBuffer` [in]

A pointer to a
[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure.

### `Context` [in]

A pointer to a block of driver-allocated context information that contains information about the
scatter gather list. The driver provided this context information in the
**Context** member of the
[NDIS_SCATTER_GATHER_LIST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_scatter_gather_list_parameters) structure.

## Remarks

NDIS calls the
*NetProcessSGList* function that is specified at the
**ProcessSGListHandler** member of the
[NDIS_SCATTER_GATHER_LIST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_scatter_gather_list_parameters) structure within the context of the
[NdisBuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisbuildscattergatherlist) function.

The driver specified the entry point (NDIS_PROCESS_SG_LIST_HANDLER) for
*NetProcessSGList* in the NDIS_SCATTER_GATHER_LIST_PARAMETERS structure.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[NDIS_SCATTER_GATHER_LIST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_scatter_gather_list_parameters)

[NdisBuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisbuildscattergatherlist)

[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list)