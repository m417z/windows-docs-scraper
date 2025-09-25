# NdisGetRssProcessorInformation function

## Description

The
**NdisGetRssProcessorInformation** function retrieves information about the set of processors that a
miniport driver must use for receive side scaling (RSS).

## Parameters

### `NdisHandle` [in]

An NDIS instance handle that was obtained during caller initialization. NDIS drivers can use the
handles from the following functions:

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

### `RssProcessorInfo` [out, optional]

A pointer to a caller-allocated buffer where NDIS puts the
[NDIS_RSS_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor_info) structure
and an array of
[NDIS_RSS_PROCESSOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor) structures that
contain information about the RSS processor set. The caller provides the length of the buffer in the
*Size* parameter.

### `Size` [in, out]

A pointer to a value that is the size, in bytes, of the buffer that the caller provided. When the
function returns, this member contains either the amount of data that NDIS put in the buffer or the
required size of the buffer if the buffer was too short.

## Return value

**NdisGetRssProcessorInformation** can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The size that was specified in *Size* parameter was too small. In this case, NDIS provides the required buffer size in the *Size* parameter. |

## Remarks

NDIS drivers call the
**NdisGetRssProcessorInformation** function to retrieve information about the receive side scaling
(RSS) processors on the local computer.

RSS-capable miniport drivers that support MSI-X call
**NdisGetRssProcessorInformation** in their
[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp) function. Miniport drivers set the interrupt affinity of the
allocated MSI-X messages to the RSS processors that are specified in the
**RssProcessors** member of the
*RssProcessorInfo* parameter.

## See also

[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_RSS_PROCESSOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor)

[NDIS_RSS_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor_info)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)