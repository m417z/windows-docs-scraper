# _WWAN_GSM_SERVING_CELL_INFO structure

## Description

The **WWAN_GSM_SERVING_CELL_INFO** structure represents information about the GSM serving cell.

## Members

### `ProviderIdOffset`

The offset in bytes, calculated from the beginning of this structure, to a numeric (0-9) string called *ProviderId* that represents the network provider identity. This string is a concatenation of a three-digit Mobile Country Code (MCC) and a two or three-digit Mobile Network Code (MNC). This member can be NULL when no *ProviderId* information is returned.

### `ProviderIdSize`

The size, in bytes, used for *ProviderId*.

### `LocationAreaCode`

The Location Area Code (0-65535). Use 0xFFFFFFFF when this information is not available.

### `CellId`

The Cell ID (0-65535). Use 0xFFFFFFFF when this information is not available.

### `TimingAdvance`

The Timing Advance (0-255) in bit periods, where a bit period is 48/13µs. Use 0xFFFFFFFF when this information is not available.

### `ARFCN`

The Absolute Radio Frequency Channel Number of the serving cell (0-1023). Use 0xFFFFFFFF when this information is not available.

### `BaseStationId`

The Base Station ID - the base station color code and the network identity code. Use 0xFFFFFFFF when this information is not available.

### `RxLevel`

The received signal strength (RSS) of the serving cell (0-63), where

`X = 0, if RSS < -110 dBm`

`X = 63, if RSS > -47 dBm`

`X = integer [RSS + 110], if -110 <= RSS <= -47`

Use 0xFFFFFFFF when this information is not available.

### `Data`

The data buffer containing *ProviderId*.

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[WWAN_GSM_NMR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_gsm_nmr)

[WWAN_GSM_NMR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_gsm_nmr_info)