# NetDmaPnPEventNotify function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
**NetDmaPnPEventNotify** function indicates a power state change for a NetDMA provider device.

## Parameters

### `NetDmaProviderHandle` [in]

A handle that identifies a DMA provider. A DMA provider driver receives this handle from the
NetDMA interface in a call to the
[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider) function.

### `PnPEvent` [in]

A pointer to a
[NET_DMA_PNP_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_pnp_notification) structure
that specifies a NetDMA PnP and power management event.

## Return value

This function does not return a value.

## Remarks

NetDMA provider drivers call the
**NetDmaPnPEventNotify** function to indicate a power state change for a NetDMA provider device.

To send a power management notification to the NetDMA interface, NetDMA provider drivers call the
**NetDmaPnPEventNotify** function and provide a pointer to a
[NET_DMA_PNP_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_pnp_notification) structure
at the
*PnPEvent* parameter.

A NetDMA provider driver calls
**NetDmaPnPEventNotify** at IRQL = PASSIVE_LEVEL.

## See also

[NET_DMA_PNP_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_pnp_notification)

[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider)