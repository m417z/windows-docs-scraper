## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_TYPE_PMK_NAME** structure defines the PMKR0Name or PMKR1Name (802.11r).

## Members

### `Name`

The PMKR0Name or PMKR1Name.

## Remarks

The **WDI_TYPE_PMK_NAME** structure is a parameter of the [WDI_TLV_FT_PMKR0NAME](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-ft-pmkr0name) TLV.

## See also

[WDI_TLV_FT_PMKR0NAME](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-ft-pmkr0name)