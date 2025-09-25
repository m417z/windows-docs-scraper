# _WDI_TX_PAUSE_REASON enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_TX_PAUSE_REASON enumeration defines the reasons for a TX pause.

## Constants

### `WDI_TX_PAUSE_REASON_NULL`

Reserved. This enum value does not represent a valid pause reason code.

### `WDI_TX_PAUSE_REASON_CREDIT`

General reason to use for the exhaustion of some IHV resource.

### `WDI_TX_PAUSE_REASON_PEER_CREATE`

All TIDs on a newly created peer are paused with this reason. The IHV uses this reason code to restart these TIDs. This is only applicable when the **TargetPriorityQueueing** capability is set to false.

### `WDI_TX_PAUSE_REASON_PS`

The peer is in Power Save Mode. This is only applicable when the **TargetPriorityQueueing** capability is set to false.

### `WDI_TX_PAUSE_REASON_IHV_START`

Inclusive beginning of range of valid pause reasons for IHV use.

### `WDI_TX_PAUSE_REASON_IHV_END`

Inclusive end of range of valid pause reasons for IHV use.

## See also

[WDI_TXRX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_wdi_txrx_target_capabilities)