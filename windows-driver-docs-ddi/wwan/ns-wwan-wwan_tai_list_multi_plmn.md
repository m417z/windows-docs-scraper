## Description

The **WWAN_TAI_LIST_MULTI_PLMN** structure represents a list of Tracking Area Identities (TAIs) that belong to different PLMNs (the Mobile Country Code (MCC) and Mobile Network Code (MNC)).

## Members

### `ElementCount`

The number of elements in the TAI list.

### `Tais`

A list of [**WWAN_SINGLE_TAI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_single_tai) structures. The ElementCount field specifies the number of elements.

## Remarks

## See also

[**WWAN_SINGLE_TAI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_single_tai)

[**WWAN_TAI_LIST_SINGLE_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_single_plmn)