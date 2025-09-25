## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_DATA_RATE_ENTRY** structure defines a data rate entry.

## Members

### `DataRateFlag`

Specifies data rate flags as defined in [**WDI_DATA_RATE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ne-dot11wificxtypes-wdi_data_rate_flags).

### `DataRateValue`

Specifies the data rate in units of 500 kilobits per second. The value is in the range from 0x0002 through 0xffff.

## Remarks

## See also

[**WDI_DATA_RATE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ne-dot11wificxtypes-wdi_data_rate_flags)