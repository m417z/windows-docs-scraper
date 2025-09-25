## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_EXEMPTION_PACKET_TYPE** enumeration defines the types of packet exemptions.

## Constants

### `WDI_EXEMPT_PACKET_TYPE_UNICAST:1`

Exempt unicast packets only.

### `WDI_EXEMPT_PACKET_TYPE_MULTICAST:2`

Exempt multicast and broadcast packets only.

### `WDI_EXEMPT_PACKET_TYPE_BOTH:3`

Exempt all packet types.

## Remarks

The **WDI_EXEMPTION_PACKET_TYPE** enum is a value in the [**WDI_TLV_PRIVACY_EXEMPTION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-privacy-exemption-entry) TLV.

## See also

[**WDI_TLV_PRIVACY_EXEMPTION_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-privacy-exemption-entry)