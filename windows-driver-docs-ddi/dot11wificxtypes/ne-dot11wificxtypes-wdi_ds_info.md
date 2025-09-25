## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_DS_INFO** enumeration defines values that specify whether the port is connected to the same DS that it was previously associated to.

## Constants

### `WDI_DS_CHANGED:1`

New DS.

### `WDI_DS_UNCHANGED:2`

Same DS as previously associated.

### `WDI_DS_UNKNOWN:3`

Unable to determine if the DS has changed.

### `WDI_DS_MAX:0xffffffff`

## Remarks

The **WDI_DS_INFO** enum is a value in the [**WDI_TLV_ASSOCIATION_RESULT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-association-result-parameters) TLV.

## See also

[**WDI_TLV_ASSOCIATION_RESULT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-association-result-parameters)