# DMA_CHANNELS_CPU_AFFINITY_HANDLER callback function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
*ProviderSetDmaChannelCpuAffinity* function sets the CPU affinities for the DMA channels that are
associated with a DMA provider.

## Parameters

### `ProviderContext` [in]

A pointer that identifies a DMA provider's context area. The DMA provider driver passed this
pointer to NetDMA in a call to the
[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider) function.

### `CpuAffinityArray` [in]

A pointer to an array of
[NET_DMA_CHANNEL_CPU_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_cpu_affinity) structures that specify the CPU affinities for the DMA channels that
are associated with the DMA provider.

### `CpuAffinityArraySize` [in]

The length, in bytes, of the buffer at
*CpuAffinityArray* .

## Return value

*ProviderSetDmaChannelCpuAffinity* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_RESOURCES** | The operation failed because of insufficient resources. |
| **STATUS_UNSUCCESSFUL** | The operation failed for unspecified reasons. |

## Remarks

The NetDMA interface calls a DMA provider driver's
*ProviderSetDmaChannelCpuAffinity* function to specify the CPU affinities of a DMA provider's DMA
channels. NetDMA calls
*ProviderSetDmaChannelCpuAffinity* while in the context of the
[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider) function.

Because the actual number of DMA channels is not known before a DMA provider is started, the NetDMA
interface specifies the CPU affinities for the maximum number of channels. The DMA provider supplies the
maximum number of channels in the
**MaxDmaChannelCount** member of the
[NET_DMA_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_characteristics) structure that it passes to the
**NetDmaRegisterProvider** function.

On computers that do not support MSI-X platforms, CPU affinities can be specified for the interrupt
DPCs but not for the interrupts. In this case, the NetDMA interface specifies a list of possible CPUs for
the interrupt DPC in the
**ProcessorAffinityMask** member of the
[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters) structure.

On computers that do support MSI-X, the DMA provider driver can specify interrupt affinities while
handling the
[IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements) IRP.

NetDMA calls
*ProviderSetDmaChannelCpuAffinity* at IRQL = PASSIVE_LEVEL.

## See also

[IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements)

[NET_DMA_CHANNEL_CPU_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_cpu_affinity)

[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters)

[NET_DMA_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_characteristics)

[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider)