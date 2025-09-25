# _WDI_DATA_RATE_ENTRY structure

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The
WDI_DATA_RATE_ENTRY structure defines a data rate entry.

## Members

### `DataRateFlag`

Specifies data rate flags as defined in WDI_DATA_RATE_FLAGS.

### `DataRateValue`

Specifies the data rate in units of 500 kilobits per second. The value is in the range from 0x0002 through 0xffff.