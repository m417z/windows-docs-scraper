## Description

The **WWAN_TAI_LIST** structure represents a list of Tracking Area Codes (TACs) that belong to a single PLMN (the Mobile Country Code (MCC) and Mobile Network Code (MNC)). The TAC values can be consecutive or nonconsecutive.

## Members

### `Plmn`

A [**WWAN_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_plmn) structure that represents the PLMN.

### `ElementCount`

The number of elements in the TAC list.

### `Tacs`

The TAC list. The ElementCount field specifies the number of elements.

## Remarks

## See also

[**WWAN_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_plmn)

[**WWAN_TAI_LIST_MULTI_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_multi_plmn)