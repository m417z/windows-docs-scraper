# _NET_DMA_PNP_NOTIFICATION_CODE enumeration

## Description

**Note** The NetDMA interface is not supported in Windows 8 and later.

The NET_DMA_PNP_NOTIFICATION_CODE enumeration identifies the type of a NetDMA Plug and Play (PnP)
event.

## Constants

### `NetDmaNotificationProviderRegistered`

The NetDMA provider is registered. NetDMA uses this event in the NetDMA client interface.

### `NetDmaNotificationProviderArrival`

The NetDMA provider is available for a client to use. NetDMA uses this event in the NetDMA client
interface.

### `NetDmaNotificationProviderRemoval`

The NetDMA provider was removed. NetDMA uses this event in the NetDMA client interface.

### `NetDmaNotificationChannelArrival`

The NetDMA channel is available for a client to use. NetDMA uses this event in the NetDMA client
interface.

### `NetDmaNotificationProviderPowerDown`

The NetDMA provider is powering down. A NetDMA provider driver issues the
**NetDmaNotificationProviderPowerDown** notification before it sets the DMA provider to a low-power
state.

### `NetDmaNotificationProviderPowerUp`

The NetDMA provider is powered up. NetDMA provider drivers issue the
**NetDmaNotificationProviderPowerUp** notification after the DMA provider is back to a working power
state.

### `NetDmaNotificationMax`

The total number of supported NetDMA PnP events.

## Remarks

The NET_DMA_PNP_NOTIFICATION_CODE enumeration is used in the
[NET_DMA_PNP_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_pnp_notification) structure.

## See also

[NET_DMA_PNP_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_pnp_notification)