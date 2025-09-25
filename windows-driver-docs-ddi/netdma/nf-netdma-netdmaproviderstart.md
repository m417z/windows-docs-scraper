# NetDmaProviderStart function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
**NetDmaProviderStart** function notifies the NetDMA interface that all of the DMA channels that are
associated with a DMA provider are initialized and ready for DMA transfers.

## Parameters

### `NetDmaProviderHandle` [in]

A handle that identifies a DMA provider. The DMA provider driver received this handle from the
NetDMA interface in a call to the
[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider) function.

### `ProviderAttributes` [in]

A pointer to a
[NET_DMA_PROVIDER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_attributes) structure that defines the DMA device attributes of the DMA
provider.

## Return value

None

## Remarks

DMA providers call the
**NetDmaProviderStart** function to notify the NetDMA interface that a DMA provider is started. A DMA
provider driver initializes a DMA engine and calls the
**NetDmaProviderStart** function while handling the
[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) IRP.

The DMA provider driver can also call
**NetDmaProviderStart** after the driver called the
[NetDmaProviderStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstop) function for
application-specific reasons. DMA provider drivers call
**NetDmaProviderStop** to notify the NetDMA interface that a previously started DMA provider is no
longer available.

The DMA provider driver supplies a
[NET_DMA_PROVIDER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_attributes) structure at the
*ProviderAttributes* parameter of
**NetDmaProviderStart**. The NET_DMA_PROVIDER_ATTRIBUTES structure specifies the configuration
attributes for a NetDMA provider.

Before a DMA provider driver calls
**NetDmaProviderStart**, it should be ready to handle all NetDMA interface requests, such as
allocating DMA channels and performing DMA transfers.

## See also

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[NET_DMA_PROVIDER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_attributes)

[NetDmaProviderStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstop)

[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider)