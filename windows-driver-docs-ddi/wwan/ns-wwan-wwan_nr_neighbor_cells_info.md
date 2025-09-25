## Description

The **WWAN_NR_NEIGHBOR_CELLS_INFO** structure represents information about NR neighbor cells.

## Members

### `SystemSubType`

Indicates the system subtype for which a neighbor cell information is valid. This is applicable for indicating whether a neighbor cell is either an NR or EUTRA cell corresponding to the WWAN data subclasses. For a detailed list of values, see the **dataSubclass** member of [**IS_5G_5GC_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/nf-wwan-is_5g_5gc_present).

### `ProviderIdOffset`

The offset in bytes, calculated from the beginning of this structure, to a numeric (0-9) string called *ProviderId* that represents the network provider identity. This string is a concatenation of a three-digit Mobile Country Code (MCC) and a two or three-digit Mobile Network Code (MNC). This member can be NULL when no *ProviderId* information is returned.

### `ProviderIdSize`

The size, in bytes, used for *ProviderId*.

### `CellIDOffset`

The offset of the *CellID* in bytes, calculated from beginning of structure. This member can be NULL when no *CellID* information is available.

### `CellIDSize`

The size used for the *CellID*.

### `PhysicalCellID`

The physical Cell ID (0-1007). Use 0xFFFFFFFF when this information is not available.

### `TAC`

The Tracking Area Code (TAC) is a 24-bit value for EUTRA-5GC or a 16-bit value for EUTRA-EPC. It is used to identify the tracking area within the scope of a public land mobile network (PLMN). Use 0xFFFFFFFF when this information is not available.

### `RSRP`

The average Reference Signal Received Power. The range is 0 to 127 and mapped to -156 to -31 dBm. Use 0xFFFFFFFF when this information is not available.

### `RSRQ`

The average Reference Signal Received Quality. The range is 0 to 127 and mapped to -43 to 20 dB. Use 0xFFFFFFFF when this information is not available.

### `SINR`

The average Reference Signal to Noise and Interference Ratio. The range is 0 to 127 and mapped to -23 to 40 dB. Use 0xFFFFFFFF when this information is not available.

### `Data`

The data buffer containing the *ProviderId* and *CellID*.

## Remarks

## See also

[**WWAN_BASE_STATIONS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[**WWAN_NR_NEIGHBOR_CELLS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_neighbor_cells)

[**WWAN_NR_SERVING_CELLS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_serving_cells)

[**WWAN_NR_SERVING_CELLS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_serving_cells_info)