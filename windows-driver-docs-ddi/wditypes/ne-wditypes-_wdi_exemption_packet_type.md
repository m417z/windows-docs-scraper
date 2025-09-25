# _WDI_EXEMPTION_PACKET_TYPE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_EXEMPTION_PACKET_TYPE enumeration defines the types of packet exemptions.

## Constants

### `WDI_EXEMPT_PACKET_TYPE_UNICAST`

Exempt unicast packets only.

### `WDI_EXEMPT_PACKET_TYPE_MULTICAST`

Exempt multicast and broadcast packets only.

### `WDI_EXEMPT_PACKET_TYPE_BOTH`

Exempt all packet types.