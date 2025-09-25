# _WWAN_GSM_NMR structure

## Description

The **WWAN_GSM_NMR** structure represents the network measurement report (NMR) of neighboring GSM cells.

## Members

### `ElementCount`

The count of NMR entries following this member.

### `GSMNmr`

The array of NMR records, each specified as a [WWAN_GSM_NMR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_gsm_nmr_info) structure.

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[WWAN_GSM_NMR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_gsm_nmr_info)

[WWAN_GSM_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_gsm_serving_cell_info)