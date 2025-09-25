# _DOT11_SUPPORTED_DSSS_CHANNEL_LIST structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_SUPPORTED_DSSS_CHANNEL_LIST structure specifies a list of frequency channels that the
802.11 station can operate with.

## Members

### `uNumOfEntries`

The number of entries in the
**dot11SupportedDSSSChannel** array.

### `uTotalNumOfEntries`

The maximum number of entries that the
**dot11SupportedDSSSChannel** array can contain.

### `dot11SupportedDSSSChannel`

An array that specifies the list of supported frequency channels that the NIC can operate with.
Each element in this list is formatted as a
[DOT11_SUPPORTED_DSSS_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_dsss_channel) structure.

## Syntax

```cpp
typedef struct _DOT11_SUPPORTED_DSSS_CHANNEL_LIST {
  ULONG                        uNumOfEntries;
  ULONG                        uTotalNumOfEntries;
  DOT11_SUPPORTED_DSSS_CHANNEL dot11SupportedDSSSChannel[1];
} DOT11_SUPPORTED_DSSS_CHANNEL_LIST, *PDOT11_SUPPORTED_DSSS_CHANNEL_LIST;
```

## Remarks

A miniport driver returns the DOT11_SUPPORTED_DSSS_CHANNEL_LIST structure when queried by
[OID_DOT11_SUPPORTED_DSSS_CHANNEL_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-dsss-channel-list).

## See also

[OID_DOT11_SUPPORTED_DSSS_CHANNEL_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-dsss-channel-list)

[DOT11_SUPPORTED_DSSS_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_dsss_channel)