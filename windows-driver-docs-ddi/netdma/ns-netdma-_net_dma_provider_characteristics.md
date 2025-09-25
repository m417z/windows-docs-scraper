# _NET_DMA_PROVIDER_CHARACTERISTICS structure

## Description

**Note** The NetDMA interface is not supported in Windows 8 and later.

The NET_DMA_PROVIDER_CHARACTERISTICS structure specifies the characteristics for a NetDMA provider,
including the entry points for the
*ProviderXxx* functions.

## Members

### `MajorVersion`

The major version number of the DMA provider driver.

### `MinorVersion`

The minor version number of the DMA provider driver.

### `Size`

The size, in bytes, of this NET_DMA_PROVIDER_CHARACTERISTICS structure. Set this member to
sizeof(NET_DMA_PROVIDER_CHARACTERISTICS).

### `Flags`

DMA provider characteristics flags. NetDMA 1.0 and 1.1 drivers set this member to zero.

NetDMA 2.0 and later drivers can use the following flags.

#### NET_DMA_PROVIDER_CHARACTERISTICS_DCA_SUPPORTED

The NetDMA provider supports
[Direct Cache Access (DCA)](https://learn.microsoft.com/windows-hardware/drivers/network/direct-cache-access--dca-).

### `PhysicalDeviceObject`

The physical device object (PDO) that is associated with the DMA provider. The Plug and Play (PnP)
manager supplies a pointer to the PDO at the
*PhysicalDeviceObject* parameter to the
[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

### `MaxDmaChannelCount`

The maximum number of DMA channels that the DMA provider can support.

### `SetDmaChannelCpuAffinity`

The entry point for the
[ProviderSetDmaChannelCpuAffinity](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channels_cpu_affinity_handler) function.

### `AllocateDmaChannel`

The entry point for the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function.

### `FreeDmaChannel`

The entry point for the
[ProviderFreeDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_free_handler) function.

### `StartDma`

The entry point for the
[ProviderStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_start_handler) function.

### `SuspendDma`

The entry point for the
[ProviderSuspendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_suspend_handler) function. If this
function is not supported, set this member to **NULL**.

### `ResumeDma`

The entry point for the
[ProviderResumeDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_resume_handler) function. If this
function is not supported, set this member to **NULL**.

### `AbortDma`

The entry point for the
[ProviderAbortDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_abort_handler) function. If this
function is not supported, set this member to **NULL**.

### `AppendDma`

The entry point for the
[ProviderAppendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_append_handler) function.

### `ResetChannel`

The entry point for the
[ProviderResetChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_reset_handler) function. If
this function is not supported, set this member to **NULL**.

### `FriendlyName`

A Unicode string that represents the user-readable description of the NetDMA provider
driver.

## Remarks

To register a DMA provider, a DMA provider driver calls the
[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider) function
from its
[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

The DMA provider driver supplies a NET_DMA_PROVIDER_CHARACTERISTICS structure at the
*ProviderCharacteristics* parameter of
**NetDmaRegisterProvider**.

## See also

[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device)

[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider)

[ProviderAbortDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_abort_handler)

[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler)

[ProviderAppendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_append_handler)

[ProviderFreeDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_free_handler)

[ProviderResetChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_reset_handler)

[ProviderResumeDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_resume_handler)

[ProviderSetDmaChannelCpuAffinity](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channels_cpu_affinity_handler)

[ProviderStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_start_handler)

[ProviderSuspendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_suspend_handler)