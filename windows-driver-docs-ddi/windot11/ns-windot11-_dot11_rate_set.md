# _DOT11_RATE_SET structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_RATE_SET structure defines the set of data rates that the 802.11 station supports.

## Members

### `uRateSetLength`

The number of entries in the
**ucRateSet** array.

### `ucRateSet`

The set of data rates.

## Syntax

```cpp
typedef struct _DOT11_RATE_SET {
  ULONG uRateSetLength;
  UCHAR ucRateSet[DOT11_RATE_SET_MAX_LENGTH];
} DOT11_RATE_SET, *PDOT11_RATE_SET;
```

## Remarks

The values that are specified in the
**ucRateSet** array define the data rates at which the 802.11 station may transmit and receive data.
Each value is an index into the table of data rates that are returned by the driver for a query of
[OID_DOT11_DATA_RATE_MAPPING_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-data-rate-mapping-table).

## See also

[OID_DOT11_DATA_RATE_MAPPING_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-data-rate-mapping-table)

[OID_DOT11_OPERATIONAL_RATE_SET](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-operational-rate-set)