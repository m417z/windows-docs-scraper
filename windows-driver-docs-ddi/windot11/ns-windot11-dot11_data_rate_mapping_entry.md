# DOT11_DATA_RATE_MAPPING_ENTRY structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_DATA_RATE_MAPPING_ENTRY structure defines a data rate supported by a PHY on the 802.11
station for transmit and receive operations.

## Members

### `ucDataRateIndex`

The index value for the data rate contained in the
**usDataRateValue** member. The value of the
**ucDataRateIndex** member must be unique for each entry in the
**DataRateMappingEntries** array.

This value is a bitmask as defined in the following table.

| Bits | Description |
| --- | --- |
| 0-6 | The data rate index, containing a value from 2 through127. |
| 7 | This bit is not used and must be set to zero. |

### `ucDataRateFlag`

The attributes of the data rate entry.

This value is a bitmask as defined in the following table.

| Bits | Name | Description |
| --- | --- | --- |
| 0 | **DOT11_DATA_RATE_NON_STANDARD** | If set, the entry is not a standard data rate defined in IEEE 802.11 standards. |
| 1-7 |  | These bits are not used and must be set to zero. |

### `usDataRateValue`

The data rate, defined in units of 500 kilobits per second (Kbps), with a value from 0x0002 to
0xFFFF.

## Syntax

```cpp
typedef struct DOT11_DATA_RATE_MAPPING_ENTRY {
  UCHAR  ucDataRateIndex;
  UCHAR  ucDataRateFlag;
  USHORT usDataRateValue;
} DOT11_DATA_RATE_MAPPING_ENTRY, *PDOT11_DATA_RATE_MAPPING_ENTRY;
```

## Remarks

For the IEEE 802.11 standard data rates, the miniport driver must set the
**ucDataRateIndex** and
**usDataRateValue** members to the same value.

The following table shows the IEEE 802.11 standard data rates, in units of megabits per second (Mbps),
and the related values for the
**ucDataRateIndex** and
**usDataRateValue** members.

| IEEE 802.11 Standard Rate | ucDataRateIndex | usDataRateValue |
| --- | --- | --- |
| 1 Mbps | 0x02 | 0x02 |
| 2 Mbps | 0x04 | 0x04 |
| 3 Mbps | 0x06 | 0x06 |
| 4.5 Mbps | 0x09 | 0x09 |
| 5.5 Mbps | 0x0B | 0x0B |
| 6 Mbps | 0x0C | 0x0C |
| 9 Mbps | 0x12 | 0x12 |
| 11 Mbps | 0x16 | 0x16 |
| 12 Mbps | 0x18 | 0x18 |
| 18 Mbps | 0x24 | 0x24 |
| 22 Mbps | 0x2C | 0x2C |
| 24 Mbps | 0x30 | 0x30 |
| 27 Mbps | 0x36 | 0x36 |
| 33 Mbps | 0x42 | 0x42 |
| 36 Mbps | 0x48 | 0x48 |
| 48 Mbps | 0x60 | 0x60 |
| 54 Mbps | 0x6C | 0x6C |

## See also

[DOT11_PHY_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_phy_attributes)

[OID_DOT11_DATA_RATE_MAPPING_TABLE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-data-rate-mapping-table)