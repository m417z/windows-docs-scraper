# _WWAN_TDSCDMA_SERVING_CELL_INFO structure

## Description

The **WWAN_TDSCDMA_SERVING_CELL_INFO** structure represents information about the TDSCDMA serving cell.

## Members

### `ProviderIdOffset`

The offset in bytes, calculated from the beginning of this structure, to a numeric (0-9) string called *ProviderId* that represents the network provider identity. This string is a concatenation of a three-digit Mobile Country Code (MCC) and a two or three-digit Mobile Network Code (MNC). This member can be NULL when no *ProviderId* information is returned.

### `ProviderIdSize`

The size, in bytes, used for *ProviderId*.

### `LocationAreaCode`

The Location Area Code (0-65535). Use 0xFFFFFFFF when this information is not available.

### `CellId`

The Cell ID (0-268435455). Use 0xFFFFFFFF when this information is not available.

### `UARFCN`

The UTRA Absolute Radio Frequency Channel Number for the serving cell (0-16383). Use 0xFFFFFFFF when this information is not available.

### `CellParameterId`

The Cell Parameter ID (0-127). Use 0xFFFFFFFF when this information is not available.

### `TimingAdvance`

The Timing Advance (0-1023). This member is the same value for all timeslots. Use 0xFFFFFFFF when this information is not available.

### `RSCP`

The Received Signal Code Power of the serving cell. The range is -120 to -25, in units of 1dBm in Q8 L3 filtered. Use 0xFFFFFFFF when this information is not available.

### `PathLoss`

The path loss of the serving cell (46-158). Use 0xFFFFFFFF when this information is not available.

### `Data`

The data buffer containing *ProviderId*.

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[WWAN_TDSCDMA_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_tdscdma_mrl)

[WWAN_TDSCDMA_MRL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_tdscdma_mrl_info)