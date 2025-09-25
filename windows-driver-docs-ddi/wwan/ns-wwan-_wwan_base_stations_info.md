# _WWAN_BASE_STATIONS_INFO structure

## Description

The **WWAN_BASE_STATIONS_INFO** structure represents information about both serving and neighboring base stations.

## Members

### `SystemType`

Indicates the system type (or types) for which serving cell information is valid. This member is a bitmask of one or more system types as defined in the **WwanDataClass** member of [WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps).

### `SystemSubType`

Indicates the 5G data subclass for which serving cell information is valid. This member is a bitmask of one or more system subtypes as defined in the **dataSubclass** member of [IS_5G_5GC_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/nf-wwan-is_5g_5gc_present). This member is only valid when the **SystemType** field above indicates that 5G serving cell information is valid. Otherwise, this value should be **WWAN_DATA_SUBCLASS_NONE**.

### `GSMServingCellOffset`

The offset in bytes, calculated from the beginning of this structure, to the buffer containing the GSM serving cell information. This member can be NULL when the technology of the serving cell is not GSM.

### `GSMServingCellSize`

The size, in bytes, used for the buffer containing the GSM serving cell info, which is formatted as [WWAN_GSM_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_gsm_serving_cell_info).

### `UMTSServingCellOffset`

The offset in bytes, calculated from the beginning of this structure, to the buffer containing the UMTS serving cell information. This member can be NULL when the technology of serving cell is not UMTS.

### `UMTSServingCellSize`

The size, in bytes, used for the buffer containing the UMTS serving cell info, which is formatted as [WWAN_UMTS_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_umts_serving_cell_info).

### `TDSCDMAServingCellOffset`

The offset in bytes, calculated from the beginning of this structure, to the buffer containing the TDSCDMA serving cell information. This member can be NULL when the technology of serving cell is not TDSCDMA.

### `TDSCDMAServingCellSize`

The size, in bytes, used for the buffer containing the TDSCDMA serving cell info, which is formatted as [WWAN_TDSCDMA_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_tdscdma_serving_cell_info).

### `LTEServingCellOffset`

The offset in bytes, calculated from the beginning of this structure, to the buffer containing the LTE serving cell information. This member can be NULL when the technology of serving cell is not LTE.

### `LTEServingCellSize`

The size, in bytes, used for the buffer containing the LTE serving cell info, which is formatted as [WWAN_LTE_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_lte_serving_cell_info).

### `GSMNmrOffset`

The offset in bytes, calculated from the beginning of this structure, to the buffer containing the GSM network measurement report. This member can be NULL when no GSM neighboring network is returned in the measurement report.

### `GSMNmrSize`

The size, in bytes, of the buffer containing the GSM network measurement report (NMR), which is formatted as [WWAN_GSM_NMR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_gsm_nmr).

### `UMTSMrlOffset`

The offset in bytes, calculated from the beginning of this structure, to the buffer containing UMTS measured results list. This member can be NULL when no UMTS neighboring network is returned in the measurement report.

### `UMTSMrlSize`

The size, in bytes, of the buffer containing the UMTS measured results list (MRL), which is formatted as [WWAN_UMTS_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_umts_mrl).

### `TDSCDMAMrlOffset`

The offset in bytes, calculated from the beginning of this structure, to the buffer containing TDSCDMA measured results list. This member can be NULL when no TDSCDMA neighboring network is returned in the measurement report.

### `TDSCDMAMrlSize`

The size, in bytes, of the buffer containing the TDSCDMA measured results list (MRL), which is formatted as [WWAN_TDSCDMA_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_tdscdma_mrl).

### `LTEMrlOffset`

The offset in bytes, calculated from the beginning of this structure, to the buffer containing LTE measured results list. This member can be NULL when no LTE neighboring network is returned in the measurement report.

### `LTEMrlSize`

The size, in bytes, of the buffer containing the LTE measured results list (MRL), which is formatted as [WWAN_LTE_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_lte_mrl).

### `CDMAMrlOffset`

The offset in bytes, calculated from the beginning of this structure, to the buffer containing CDMA measured results list. This member can be NULL when no CDMA neighboring network is returned in the measurement report.

### `CDMAMrlSize`

The size, in bytes, of the buffer containing the CDMA measured results list (MRL), which is formatted as [WWAN_CDMA_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_cdma_mrl).

### `NRServingCellsOffset`

The offset in bytes, calculated from the beginning of this structure, to the buffer containing the NR measure results list. This member can be NULL when no NR serving cells are available for devices without 5G capability.

### `NRServingCellsSize`

The size, in bytes, of the buffer containing the 5G NR measured results, which is formatted as [WWAN_NR_SERVING_CELLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_serving_cells).

### `NRNeighborCellsOffset`

The offset in bytes, calculated from the beginning of this structure, to the buffer containing the NR neighbor cells measurement results. This member can be NULL when no NR neighbor cells are available.

### `NRNeighborCellsSize`

The size, in bytes, of the buffer containing the NR measured results, which is formatted as [WWAN_NR_NEIGHBOR_CELLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_neighbor_cells).

### `BaseStationsData`

[ANYSIZE_ARRAY] The data buffer containing the base stations information. This buffer is where the structures specified by the other members of **WWAN_BASE_STATIONS_INFO** reside.

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[NDIS_WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_base_stations_info)

[WWAN_CDMA_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_cdma_mrl)

[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps)

[WWAN_GSM_NMR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_gsm_nmr)

[WWAN_GSM_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_gsm_serving_cell_info)

[WWAN_LTE_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_lte_mrl)

[WWAN_LTE_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_lte_serving_cell_info)

[WWAN_TDSCDMA_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_tdscdma_mrl)

[WWAN_TDSCDMA_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_tdscdma_serving_cell_info)

[WWAN_UMTS_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_umts_mrl)

[WWAN_UMTS_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_umts_serving_cell_info)