## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_P2P_CHANNEL_INDICATE_REASON** enumeration defines Wi-Fi Direct channel indication reason values.

## Constants

### `WDI_P2P_CHANNEL_INDICATE_REASON_UNKNOWN`

### `WDI_P2P_CHANNEL_INDICATE_REASON_NEW_CONNECTION:0x0001`

New connection set up.

### `WDI_P2P_CHANNEL_INDICATE_REASON_ECSA_REQUESTED:0x0002`

eCSA request from the peer.

### `WDI_P2P_CHANNEL_INDICATE_REASON_ECSA_GO_INITIATED:0x0003`

eCSA initiated by GO.

### `WDI_P2P_CHANNEL_INDICATE_REASON_MAX`

## Remarks

The **WDI_P2P_CHANNEL_INDICATE_REASON** enum is a value in the [**WDI_TLV_P2P_CHANNEL_INDICATE_REASON**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-channel-indicate-reason) TLV.

## See also

[**WDI_TLV_P2P_CHANNEL_INDICATE_REASON**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-channel-indicate-reason)