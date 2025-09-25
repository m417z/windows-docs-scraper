## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is now in maintenance mode and will only receive high priority fixes.

The **WDI_P2P_SERVICE_NAME_HASH** structure defines a hash of a WFDS Service Name.

## Members

### `Hash`

Hash of a WFDS Service Name. This may also be a hash of an ASP2 Service Type or ASP2 Service Type and Instance Name.

## Remarks

The **WDI_P2P_SERVICE_NAME_HASH** structure is a value in the [**WDI_TLV_P2P_SERVICE_NAME_HASH**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-service-name-hash) TLV.

## See also

[**WDI_TLV_P2P_SERVICE_NAME_HASH**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-service-name-hash)