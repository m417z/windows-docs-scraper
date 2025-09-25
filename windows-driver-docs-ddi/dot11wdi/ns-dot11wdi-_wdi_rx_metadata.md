# _WDI_RX_METADATA structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
WDI_RX_METADATA structure defines the RX metadata.

The RX Engine specifies this metadata in the **rxMetadata** section of the [WDI_FRAME_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_frame_metadata) buffer attached to each [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) (in MiniportReserved[0]). Each NET_BUFFER_LIST represents an MPDU. The IHV miniport driver must not allocate a [DOT11_EXTSTA_RECV_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_extsta_recv_context) structure as this is handled by WDI.

## Members

### `PayloadType`

The payload type, specified for each MPDU.

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[WDI_FRAME_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_frame_metadata)