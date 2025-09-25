# _DOT11_SUPPORTED_OFDM_FREQUENCY structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_SUPPORTED_OFDM_FREQUENCY structure specifies a supported channel center frequency entry in
a
[DOT11_SUPPORTED_OFDM_FREQUENCY_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_ofdm_frequency_list) structure.

## Members

### `uCenterFrequency`

A ULONG value that represents a channel center frequency, in MHz, that the 802.11 station can
operate with.

## Syntax

```cpp
typedef struct _DOT11_SUPPORTED_OFDM_FREQUENCY {
  ULONG uCenterFrequency;
} DOT11_SUPPORTED_OFDM_FREQUENCY, *PDOT11_SUPPORTED_OFDM_FREQUENCY;
```

## See also

[DOT11_SUPPORTED_OFDM_FREQUENCY_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_ofdm_frequency_list)