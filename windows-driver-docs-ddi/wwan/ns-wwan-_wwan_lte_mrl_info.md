# _WWAN_LTE_MRL_INFO structure

## Description

The **WWAN_LTE_MRL_INFO** structure represents information about a neighboring LTE cell.

## Members

### `ProviderIdOffset`

The offset in bytes, calculated from the beginning of this structure, to a numeric (0-9) string called *ProviderId* that represents the network provider identity. This string is a concatenation of a three-digit Mobile Country Code (MCC) and a two or three-digit Mobile Network Code (MNC). This member can be NULL when no *ProviderId* information is returned.

### `ProviderIdSize`

The size, in bytes, used for *ProviderId*.

### `CellId`

The Cell ID (0-268435455). Use 0xFFFFFFFF when this information is not available.

### `EARFCN`

The Radio Frequency Channel Number of the serving cell (0-65535). Use 0xFFFFFFFF when this information is not available.

### `PhysicalCellId`

The Physical Cell ID (0-503). Use 0xFFFFFFFF when this information is not available.

### `TAC`

The Tracking Area Code (0-65535). Use 0xFFFFFFFF when this information is not available.

### `RSRP`

The Average Reference Signal Received Power. The range is -140 to -44, in units of 1dBm. Use 0xFFFFFFFF when this information is not available.

### `RSRQ`

The Average Reference Signal Received Quality. The range is -20 to -3, in units of 1dBm. Use 0xFFFFFFFF when this information is not available.

### `Data`

The data buffer containing *ProviderId*.

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[WWAN_LTE_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_lte_mrl)

[WWAN_LTE_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_lte_serving_cell_info)