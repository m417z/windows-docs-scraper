# NdisGetProcessorInformation function

## Description

The
**NdisGetProcessorInformation** function retrieves information about the CPU topology of the local
computer and the set of processors that a miniport driver must use for receive side scaling (RSS).

## Parameters

### `SystemProcessorInfo` [in, out]

A pointer to an
[NDIS_SYSTEM_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_system_processor_info) structure that NDIS fills with the information about the CPU topology
of the system and the RSS processor set.

## Return value

**NdisGetProcessorInformation** can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The size that was specified in the **Header.Size** member of the *SystemProcessorInfo* parameter was too small. |

## Remarks

NDIS drivers call the
**NdisGetProcessorInformation** function to retrieve information about the processors on the local
computer.

RSS-capable miniport drivers that support MSI-X call
**NdisGetProcessorInformation** in their
[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp) function. Miniport drivers set the interrupt affinity of the
allocated MSI-X messages to the RSS processors that are specified in the
**RssProcessors** member of the
*SystemProcessorInfo* parameter.

## See also

[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp)

[NDIS_SYSTEM_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_system_processor_info)

[NdisGetProcessorInformationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetprocessorinformationex)

[NdisGetRssProcessorInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetrssprocessorinformation)