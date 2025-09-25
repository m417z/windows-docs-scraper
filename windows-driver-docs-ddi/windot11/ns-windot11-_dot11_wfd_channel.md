# _DOT11_WFD_CHANNEL structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_CHANNEL** structure contains the channel information for a Peer-to-Pear (P2P) group.

## Members

### `CountryRegionString`

The country or region code where **OperatingClass** and **ChannelNumber** are valid.

### `OperatingClass`

The frequency band for **ChannelNumber**.

### `ChannelNumber`

The channel number for the P2P group.

## Syntax

```cpp
typedef struct _DOT11_WFD_CHANNEL {
  DOT11_COUNTRY_OR_REGION_STRING CountryRegionString;
  UCHAR                          OperatingClass;
  UCHAR                          ChannelNumber;
} DOT11_WFD_CHANNEL, *PDOT11_WFD_CHANNEL;
```