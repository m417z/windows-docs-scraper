# _NET_DMA_PNP_NOTIFICATION structure

## Description

**Note** The NetDMA interface is not supported in Windows 8 and later.

The NET_DMA_PNP_NOTIFICATION structure specifies a power management notification in the NetDMA
interface.

## Members

### `StructureRevision`

The revision for this structure. The NetDMA provider driver must set this member to
NET_DMA_PNP_NOTIFICATION_REVISION_1.

### `StructureSize`

The size, in bytes, of the notification structure. This size does not include the size of the
notification specific data at
**Buffer**, if any. A NetDMA provider driver must set this member to
sizeof(NET_DMA_PNP_NOTIFICATION).

### `NotificationCode`

A value that identifies the DMA provider event. This value must be one of the values from the
[NET_DMA_PNP_NOTIFICATION_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ne-netdma-_net_dma_pnp_notification_code) enumeration.

### `Buffer`

A pointer to notification-specific data, if any. NetDMA provider drivers set this member to **NULL**
for
**NetDmaNotificationProviderPowerDown** and
**NetDmaNotificationProviderPowerUp** notifications.

### `BufferLength`

The length, in bytes, of the notification-specific data at the
**Buffer** member. NetDMA provider drivers set this member to zero for
**NetDmaNotificationProviderPowerDown** and
**NetDmaNotificationProviderPowerUp** notifications.

## Remarks

To send a power management notification to the NetDMA interface, NetDMA provider drivers call the
[NetDmaPnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmapnpeventnotify) function and
provide a pointer to a NET_DMA_PNP_NOTIFICATION structure at the
*PnPEvent* parameter.

## See also

[NET_DMA_PNP_NOTIFICATION_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ne-netdma-_net_dma_pnp_notification_code)

[NetDmaPnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmapnpeventnotify)