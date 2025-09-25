## Description

The **WWAN_NR_SERVING_CELLS_INFO** structure represents information about NR serving cells.

## Members

### `ProviderIdOffset`

The offset in bytes, calculated from the beginning of this structure, to a numeric (0-9) string called *ProviderId* that represents the network provider identity. This string is a concatenation of a three-digit Mobile Country Code (MCC) and a two or three-digit Mobile Network Code (MNC). This member can be NULL when no *ProviderId* information is returned.

### `ProviderIdSize`

The size, in bytes, used for *ProviderId*.

### `NCI`

The NR Cell Identity is a 36-bit identity having a value range of 0 to 68719476736. An NR Cell Global Identity (NCGI) can be constructed from *ProviderId* and **NCI**. Use 0xFFFFFFFF when this information is not available.

### `PhysicalCellID`

The physical Cell ID (0-1007). Use 0xFFFFFFFF when this information is not available.

### `NRARFCN`

The Absolute Radio Frequency Channel Number of the serving cells. The range is 0 to 3279165. Use 0xffffffff when the information is not available.

### `TAC`

The Tracking Area Code (TAC) is a 24-bit value range (0 to 16777215). It is used to identify the tracking area within the scope of a public land mobile network (PLMN). Use 0xFFFFFFFF when this information is not available.

### `RSRP`

The average Reference Signal Received Power. The range is 0 to 127 and mapped to -156 to -31 dBm. Use 0xFFFFFFFF when this information is not available.

### `RSRQ`

The average Reference Signal Received Quality. The range is 0 to 127 and mapped to -43 to 20 dB. Use 0xFFFFFFFF when this information is not available.

### `SINR`

The average Reference Signal to Noise and Interference Ratio. The range is 0 to 127 and mapped to -23 to 40 dB. Use 0xFFFFFFFF when this information is not available.

### `TimingAdvance`

The timing advance value in microseconds, where the formula is defined in section 7.2 in [5G; NR; Requirements for support of radio resource management](https://www.etsi.org/deliver/etsi_ts/138100_138199/138133/15.06.00_60/ts_138133v150600p.pdf). Use 0xFFFFFFFF when this information is not available.

### `Data`

The data buffer containing the *ProviderId*.

## Remarks

## See also

[**WWAN_BASE_STATIONS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[**WWAN_NR_SERVING_CELLS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_serving_cells)

[**WWAN_NR_NEIGHBOR_CELLS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_neighbor_cells_info)

[**WWAN_NR_NEIGHBOR_CELLS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_neighbor_cells)