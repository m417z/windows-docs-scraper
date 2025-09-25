# DMA_CHANNEL_ALLOCATE_HANDLER callback function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
*ProviderAllocateDmaChannel* function allocates a DMA channel.

## Parameters

### `ProviderContext` [in]

A pointer that identifies a DMA provider's context area. The DMA provider driver passes this
handle to the NetDMA interface in a call to the
[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider) function.

### `ChannelParameters` [in]

A pointer to a
[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters) structure that defines the configuration parameters for the DMA
channel.

### `NetDmaChannelHandle` [in]

A handle that identifies the DMA channel. Provider drivers pass this handle to
**NetDma*Xxx*** functions to identify the DMA channel.

### `pProviderChannelContext` [out]

A pointer to a value that is a pointer to a DMA provider's context area for the DMA channel. The
DMA provider driver allocates this context area before returning from
*ProviderAllocateDmaChannel*. NetDMA passes the context area pointer to
*ProviderXxx* functions that require a provider channel context.

## Return value

*ProviderAllocateDmaChannel* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_RESOURCES** | The operation failed because of insufficient resources. |
| **STATUS_UNSUCCESSFUL** | The operation failed for unspecified reasons. |

## Remarks

The NetDMA interface calls a DMA provider driver's
*ProviderAllocateDmaChannel* function to allocate a DMA channel. The NetDMA interface calls
*ProviderAllocateDmaChannel* before it uses a DMA channel.

The DMA provider driver attempts to allocate a DMA channel with an interrupt CPU affinity that matches
a bit that is specified in the
**ProcessorAffinityMask** member of the
[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters) structure at the
*ChannelParameters* parameter. If MSI-X is not supported or MSI-X is supported but a DMA channel with
a matching interrupt CPU affinity is not available, the DMA provider driver allocates any available DMA
channel and calls the
[KeSetTargetProcessorDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesettargetprocessordpc) routine to
set the target CPU of the interrupt DPC to match one of the specified affinity mask bits.

The DMA provider always driver returns the CPU number that it associated with the interrupt DPC for
the DMA channel to the NetDMA interface in the
**CpuNumber** member of the NET_DMA_CHANNEL_PARAMETERS structure.

The DMA provider driver provides a pointer to a block of driver-allocated context information at the
*pProviderChannelContext* parameter of
*ProviderAllocateDmaChannel*. This context area stores information about the DMA channel. The NetDMA
interface passes the context information in subsequent calls to
*ProviderXxx* functions that require a DMA channel context.

When the NetDMA interface calls
*ProviderAllocateDmaChannel*, it provides a handle at the
*NetDmaChannelHandle* parameter. The DMA provider driver uses this handle in subsequent calls to
**NetDma*Xxx*** functions that are associated with the DMA channel.

The NetDMA interface calls the
[ProviderFreeDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_free_handler) function to
free a previously allocated DMA channel.

NetDMA calls
*ProviderAllocateDmaChannel* at IRQL <= DISPATCH_LEVEL.

## See also

[KeSetTargetProcessorDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesettargetprocessordpc)

[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters)

[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider)

[ProviderFreeDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_free_handler)