## Description

The **WDI_BAND_ID** enumeration is a UINT32 value that defines a band ID.

## Constants

### `WDI_BAND_ID_UNKNOWN:0`

The band ID is unknown.

### `WDI_BAND_ID_2400:1`

2.4 GHz.

### `WDI_BAND_ID_5000:2`

5 GHz.

### `WDI_BAND_ID_60000:3`

60 GHz.

### `WDI_BAND_ID_900:4`

900 MHz.

### `WDI_BAND_ID_6000:6`

6 GHz.

### `WDI_BAND_ID_IHV_CUSTOM_START:0x80000000`

Specifies the start of the range that is used to define a band ID reported by an IHV.

### `WDI_BAND_ID_IHV_CUSTOM_END:0x81000000`

Specifies the end of the range that is used to define a band ID reported by an IHV.

### `WDI_BAND_ID_ANY:0xFFFFFFFF`

All bands.

## Remarks

The **WDI_BAND_ID** enum is a value in the [**WDI_TLV_ASSOCIATION_RESULT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-association-result-parameters) TLV.

## See also

[**WDI_TLV_ASSOCIATION_RESULT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-association-result-parameters)