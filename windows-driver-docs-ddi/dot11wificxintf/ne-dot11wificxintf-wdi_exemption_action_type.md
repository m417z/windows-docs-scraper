## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is now in maintenance mode and will only receive high priority fixes.

The **WDI_EXEMPTION_ACTION_TYPE** enumeration defines exemption types.

## Constants

### `WDI_EXEMPT_NO_EXEMPTION:0`

Packets are not exempt from any cipher operations performed by the port.

### `WDI_EXEMPT_ALWAYS:1`

On send, packets are exempt from cipher operations and are transmitted unencrypted. On receive, the received packet is discarded if the Protected Frame subfield of the Frame Control field in the 802.11 MAC header is set to 1.

### `WDI_EXEMPT_ON_KEY_MAPPING_KEY_UNAVAILABLE:2`

On send, packets are exempt from cipher operations if there is no key-mapping key for the packet's destination MAC address. On receive, the received packet is discarded if a key-mapping key for the source MAC address is available and the Protected Frame subfield of the Frame Control field in the 802.11 MAC header is set to **zero**.

## Remarks

The **WDI_EXEMPTION_ACTION_TYPE** enum is a value in the [**WDI_TLV_PRIVACY_EXEMPTION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-privacy-exemption-entry) TLV.

## See also

[**WDI_TLV_PRIVACY_EXEMPTION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-privacy-exemption-entry)