# _NET_DMA_CHANNEL_CPU_AFFINITY structure

## Description

**Note** The NetDMA interface is not supported in Windows 8 and later.

The NET_DMA_CHANNEL_CPU_AFFINITY structure specifies the CPU affinity of a DMA channel.

## Members

### `DmaChannel`

The DMA channel number. The values for this member range from zero through the maximum number of
DMA channels that the DMA engine supports minus one. The DMA provider driver specifies the maximum
number of DMA channels in the
**MaxDmaChannelCount** member of the
[NET_DMA_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_characteristics) structure.

### `CpuNumber`

The target CPU that the DMA provider driver should associate with the MSI-X interrupts that are
generated for the DMA channel that is specified in the
**DmaChannel** member.

## Remarks

The NetDMA interface passes an array of NET_DMA_CHANNEL_CPU_AFFINITY structures to a DMA provider
driver's
[ProviderSetDmaChannelCpuAffinity](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channels_cpu_affinity_handler) function to specify the CPU affinity of the DMA channels.

The NetDMA interface calls
*ProviderSetDmaChannelCpuAffinity* while in the context of the
[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider) function.

## See also

[NET_DMA_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_characteristics)

[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider)

[ProviderSetDmaChannelCpuAffinity](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channels_cpu_affinity_handler)