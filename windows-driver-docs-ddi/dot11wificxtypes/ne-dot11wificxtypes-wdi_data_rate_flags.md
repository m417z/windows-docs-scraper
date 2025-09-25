## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_DATA_RATE_FLAGS** enumeration defines the data rate flags.

## Constants

### `WDI_DATA_RATE_NON_STANDARD:0x01`

The data rate is not a standard data rate defined in the IEEE 802.11 standards.

### `WDI_DATA_RATE_RX_RATE:0x02`

The data rate can be used for RX.

### `WDI_DATA_RATE_TX_RATE:0x04`

The data rate can be used for TX.

## Remarks

The **WDI_DATA_RATE_FLAGS** enum is a member of the [**WDI_DATA_RATE_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ns-dot11wificxtypes-wdi_data_rate_entry) structure.

## See also

[**WDI_DATA_RATE_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxtypes/ns-dot11wificxtypes-wdi_data_rate_entry)