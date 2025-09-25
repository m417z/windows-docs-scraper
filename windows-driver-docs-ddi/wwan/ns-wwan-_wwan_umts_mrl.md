# _WWAN_UMTS_MRL structure

## Description

The **WWAN_UMTS_MRL** structure contains the measured results list (MRL) of neighboring UMTS cells.

## Members

### `ElementCount`

The count of MRL entries following this member.

### `UMTSMrl`

The array of MRL records, each specified as a [WWAN_UMTS_MRL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_umts_mrl_info) structure.

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[WWAN_UMTS_MRL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_umts_mrl_info)

[WWAN_UMTS_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_umts_serving_cell_info)