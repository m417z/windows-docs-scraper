# _WWAN_CDMA_MRL structure

## Description

The **WWAN_CDMA_MRL** structure represents the measured results list (MRL) of both serving and neighboring CDMA cells.

## Members

### `ElementCount`

The count of MRL entries following this member.

### `CDMAMrl`

The array of MRL records, each specified as a [WWAN_CDMA_MRL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_cdma_mrl_info) structure.

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[WWAN_CDMA_MRL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_cdma_mrl_info)