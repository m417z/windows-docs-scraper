# _WDI_EXEMPTION_ACTION_TYPE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_EXEMPTION_ACTION_TYPE enumeration defines the exemption types.

## Constants

### `WDI_EXEMPT_NO_EXEMPTION`

Packets are not exempt from any cipher operations performed by the port.

### `WDI_EXEMPT_ALWAYS`

On send, packets are exempt from cipher operations and are transmitted unencrypted. On receive, the received packet is discarded if the Protected Frame subfield of the Frame Control field in the 802.11 MAC header is set to 1.

### `WDI_EXEMPT_ON_KEY_MAPPING_KEY_UNAVAILABLE`

On send, packets are exempt from cipher operations if there is no key-mapping key for the packet's destination MAC address. On receive, the received packet is discarded if a key-mapping key for the source MAC address is available and the Protected Frame subfield of the Frame Control field in the 802.11 MAC header is set to 0.