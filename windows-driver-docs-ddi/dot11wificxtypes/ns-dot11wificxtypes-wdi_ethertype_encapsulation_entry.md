## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_ETHERTYPE_ENCAPSULATION_ENTRY** structure defines an EtherType encapsulation entry.

## Members

### `EtherType`

The value of the IEEE EtherType in big-endian byte order.

### `EncapsulationType`

The type of encapsulation to be performed on the specified EtherType.

## Remarks

The **WDI_ETHERTYPE_ENCAPSULATION_ENTRY** structure is a value in the [**WDI_TLV_ETHERTYPE_ENCAP_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-ethertype-encap-table) TLV.

## See also

[**WDI_TLV_ETHERTYPE_ENCAP_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-ethertype-encap-table)