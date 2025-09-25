# _WWAN_BASE_STATIONS_INFO_REQ structure

## Description

The **WWAN_BASE_STATIONS_INFO_REQ** structure represents the aspects of cellular base stations information that are requested in a base stations information query.

## Members

### `MaxGSMCount`

The maximum number of entries of GSM neighboring cells returned in the GSM network measurement reports of [WWAN_GSM_NMR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_gsm_nmr).

### `MaxUMTSCount`

The maximum number of entries of UMTS neighboring cells returned in the UMTS measured results list in [WWAN_UMTS_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_umts_mrl).

### `MaxTDSCDMACount`

The maximum number of entries of TDSCDMA neighboring cells returned in the TDSCDMA measured results list in [WWAN_TDSCDMA_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_tdscdma_mrl).

### `MaxLTECount`

The maximum number of entries of LTE neighboring cells returned in the LTE measured results list in [WWAN_LTE_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_lte_mrl).

### `MaxCDMACount`

The maximum number of entries of CDMA cells returned in the CDMA measured results list in [WWAN_CDMA_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_cdma_mrl). This list includes both serving and neighboring cells.

### `MaxNRCount`

The maximum number of entries of both 5G NR serving cells and neighbor cells returned in the measurement results in [WWAN_NR_NEIGHBOR_CELLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_neighbor_cells) and [WWAN_NR_SERVING_CELLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_serving_cells).

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[NDIS_WWAN_BASE_STATIONS_INFO_REQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_base_stations_info_req)

[WWAN_CDMA_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_cdma_mrl)

[WWAN_GSM_NMR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_gsm_nmr)

[WWAN_LTE_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_lte_mrl)

[WWAN_TDSCDMA_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_tdscdma_mrl)

[WWAN_UMTS_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_umts_mrl)