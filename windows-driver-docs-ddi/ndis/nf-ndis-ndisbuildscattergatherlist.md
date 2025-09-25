# NdisBuildScatterGatherList function

## Description

The
**NdisBuildScatterGatherList** function builds a scatter/gather list by using the specified
parameters.

## Parameters

### `NdisHandle` [in]

An NDIS driver or instance handle that was obtained during caller initialization. For example, a
miniport driver can use the NDIS handle that it obtained from the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) or
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
Other NDIS drivers can use the handles from the following functions:

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

### `SGListParameters` [in]

A pointer to an
[NDIS_SCATTER_GATHER_LIST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_scatter_gather_list_parameters) structure that specifies the parameters for allocating the
scatter/gather list.

## Return value

**NdisBuildScatterGatherList** can return the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The operation failed because the buffer length that is specified in the **ScatterGatherListBufferSize** member of the [NDIS_SCATTER_GATHER_LIST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_scatter_gather_list_parameters) structure was too short. In this case, NDIS provided the required buffer size in the **ScatterGatherListBufferSizeNeeded** member. |

## Remarks

NDIS drivers call the
**NdisBuildScatterGatherList** function to build a scatter/gather list for a buffer. To call this
function, a miniport driver specifies a miniport adapter handle or a protocol driver specifies an NDIS
binding handle.

The underlying miniport adapter must have called
[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) before a driver can call
**NdisBuildScatterGatherList**.

NDIS calls the
[NetProcessSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_process_sg_list) function that is
specified at the
**ProcessSGListHandler** member of the
[NDIS_SCATTER_GATHER_LIST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_scatter_gather_list_parameters) structure within the context of
**NdisBuildScatterGatherList**.

The drivers must call the
[NdisFreeScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreescattergatherlist) function to free a scatter/gather list that was created with the
**NdisBuildScatterGatherList** function.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_SCATTER_GATHER_LIST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_scatter_gather_list_parameters)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NetProcessSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_process_sg_list)