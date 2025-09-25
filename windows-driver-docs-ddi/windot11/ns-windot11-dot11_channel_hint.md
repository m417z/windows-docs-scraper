# DOT11_CHANNEL_HINT structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_CHANNEL_HINT structure describes suggested channel numbers for an NLO operation.

## Members

### `Dot11PhyType`

The 802.11 PHY and media type.

### `uChannelNumber`

Channel number.

## Syntax

```cpp
typedef struct _DOT11_CHANNEL_HINT {
  DOT11_PHY_TYPE Dot11PhyType;
  ULONG          uChannelNumber;
} DOT11_CHANNEL_HINT, *PDOT11_CHANNEL_HINT;
```