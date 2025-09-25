# _DOT11_SUPPORTED_DATA_RATES_VALUE_V2 structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_SUPPORTED_DATA_RATES_VALUE_V2 structure specifies a list of transmit and receive data rates
for a PHY on the 802.11 station.

## Members

### `ucSupportedTxDataRatesValue`

An array of the transmit data rates supported by the Physical Layer Convergence Procedure (PLCP)
and Physical Media Dependent (PMD) sublayer of the PHY.

### `ucSupportedRxDataRatesValue`

An array of the receive data rates supported by the PLCP and PMD of the PHY.

## Syntax

```cpp
typedef struct _DOT11_SUPPORTED_DATA_RATES_VALUE_V2 {
  UCHAR ucSupportedTxDataRatesValue[MAX_NUM_SUPPORTED_RATES_V2];
  UCHAR ucSupportedRxDataRatesValue[MAX_NUM_SUPPORTED_RATES_V2];
} DOT11_SUPPORTED_DATA_RATES_VALUE_V2, *PDOT11_SUPPORTED_DATA_RATES_VALUE_V2;
```

## Remarks

Each entry in the
**ucSupportedTxDataRatesValue** and
**ucSupportedRxDataRatesValue** arrays must have a data rate index value as defined for the
**ucDataRateIndex** member of the
[DOT11_DATA_RATE_MAPPING_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_data_rate_mapping_entry) structure. Each entry in these arrays must match a
**ucDataRateIndex** member from the table of data rates returned through a query of
[OID_DOT11_DATA_RATE_MAPPING_TABLE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-data-rate-mapping-table). The index value must be between 2 and 127.

If the number of supported rates in either array is less than 255, the miniport driver must add an
entry with a value of zero after the last data rate in the array. For example, if the 802.11 station
supports only four transmit data rates, the miniport driver must set
**ucSupportedTxDataRatesValue[0..3]** with the four transmit rates and set
**ucSupportedTxDataRatesValue[4]** to zero.

## See also

[NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_native_802_11_attributes)

[DOT11_DATA_RATE_MAPPING_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_data_rate_mapping_entry)

[OID_DOT11_DATA_RATE_MAPPING_TABLE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-data-rate-mapping-table)

[OID_DOT11_SUPPORTED_DATA_RATES_VALUE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-supported-data-rates-value)