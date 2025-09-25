# _WDI_FRAME_METADATA structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
WDI_FRAME_METADATA structure defines the frame metadata.

## Members

### `Linkage`

Reserved for use by the Microsoft component.

### `pNBL`

Set by the LE on RX path and the UE on TX path when the metadata is associated with an NBL.

### `FrameID`

Filled in by the Microsoft component.

### `wPad`

Padding.

### `dPad`

Padding.

### `u`

### `u.txMetaData`

TX metadata.

### `u.rxMetaData`

RX metadata.

## See also

[LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[WDI_FRAME_ID](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-frame-id)

[WDI_RX_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_rx_metadata)

[WDI_TX_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_tx_metadata)