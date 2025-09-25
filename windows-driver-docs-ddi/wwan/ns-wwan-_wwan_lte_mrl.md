# _WWAN_LTE_MRL structure

## Description

The **WWAN_LTE_MRL** structure represents the measured results list (MRL) of neighboring LTE cells.

## Members

### `ElementCount`

The count of MRL entries following this member.

### `LTEMrl`

The array of MRL records, each specified as a [WWAN_LTE_MRL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_lte_mrl_info) structure.

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[WWAN_LTE_MRL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_lte_mrl_info)

[WWAN_LTE_SERVING_CELL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_lte_serving_cell_info)