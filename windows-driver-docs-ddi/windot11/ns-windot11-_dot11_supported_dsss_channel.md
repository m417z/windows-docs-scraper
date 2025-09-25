# _DOT11_SUPPORTED_DSSS_CHANNEL structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_SUPPORTED_DSSS_CHANNEL structure specifies a supported operating frequency channel entry in
a
[DOT11_SUPPORTED_DSSS_CHANNEL_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_dsss_channel_list) structure.

## Members

### `uChannel`

A ULONG value, which represents a frequency channel that the 802.11 station can operate with.
Valid channel numbers are as defined in 15.4.6.2 of
*IEEE Std. 802.11-1997* for the following PHY types:

* Direct-sequence spread spectrum (DSSS) PHY.
* High-rate DSSS (HRDSSS) PHY.
* Extended-rate PHY (ERP).
* High-throughput (HT) 802.11n PHY when operating in the 2.4-GHz band.

## Syntax

```cpp
typedef struct _DOT11_SUPPORTED_DSSS_CHANNEL {
  ULONG uChannel;
} DOT11_SUPPORTED_DSSS_CHANNEL, *PDOT11_SUPPORTED_DSSS_CHANNEL;
```

## See also

[DOT11_SUPPORTED_DSSS_CHANNEL_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_dsss_channel_list)