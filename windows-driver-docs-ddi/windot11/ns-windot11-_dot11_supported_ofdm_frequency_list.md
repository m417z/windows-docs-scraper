# _DOT11_SUPPORTED_OFDM_FREQUENCY_LIST structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_SUPPORTED_OFDM_FREQUENCY_LIST structure specifies a list of channel center frequencies that
the 802.11 station can operate with.

## Members

### `uNumOfEntries`

The number of entries in the
**dot11SupportedOFDMFrequency** array.

### `uTotalNumOfEntries`

The maximum number of entries that the
**dot11SupportedOFDMFrequency** array can contain.

### `dot11SupportedOFDMFrequency`

An array that specifies the list of supported channel center frequencies that the NIC can operate
with. Each element in this list is formatted as a
[DOT11_SUPPORTED_OFDM_FREQUENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_ofdm_frequency) structure.

## Syntax

```cpp
typedef struct _DOT11_SUPPORTED_OFDM_FREQUENCY_LIST {
  ULONG                          uNumOfEntries;
  ULONG                          uTotalNumOfEntries;
  DOT11_SUPPORTED_OFDM_FREQUENCY dot11SupportedOFDMFrequency[1];
} DOT11_SUPPORTED_OFDM_FREQUENCY_LIST, *PDOT11_SUPPORTED_OFDM_FREQUENCY_LIST;
```

## Remarks

A miniport driver returns the DOT11_SUPPORTED_OFDM_FREQUENCY_LIST structure when queried by
[OID_DOT11_SUPPORTED_OFDM_FREQUENCY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-ofdm-frequency-list).

## See also

[OID_DOT11_SUPPORTED_OFDM_FREQUENCY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-ofdm-frequency-list)

[DOT11_SUPPORTED_OFDM_FREQUENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_supported_ofdm_frequency)