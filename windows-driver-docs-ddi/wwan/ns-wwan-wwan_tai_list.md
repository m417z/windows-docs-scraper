## Description

The **WWAN_TAI_LIST** structure represents one or more Tracking Area Identity (TAI) lists.

## Members

### `TaiListType`

A value from the [**WWAN_STRUCT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_struct_type) enumeration that represents the type of the TAI list.

### `DataBuffer`

The TAI list data. The format is either [**WWAN_TAI_LIST_SINGLE_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_single_plmn) or [**WWAN_TAI_LIST_MULTI_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_multi_plmn).

## Remarks

## See also

[**WWAN_STRUCT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_struct_type)

[**WWAN_TAI_LIST_SINGLE_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_single_plmn)

[**WWAN_TAI_LIST_MULTI_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_multi_plmn)