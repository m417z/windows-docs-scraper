# MMC_FILTER_TYPE enumeration

## Description

The
**MMC_FILTER_TYPE** enumeration is introduced in MMC 1.2.

The
**MMC_FILTER_TYPE** enumeration defines the filter type that is associated with a filter applied to a column in a filtered list. The values can be used in the *dwType* parameter of the
[IHeaderCtrl2::SetColumnFilter](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iheaderctrl2-setcolumnfilter) method and the *pdwType* parameter of the
[IHeaderCtrl2::GetColumnFilter](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iheaderctrl2-getcolumnfilter) method.

## Constants

### `MMC_STRING_FILTER:0`

String filter.

### `MMC_INT_FILTER:0x1`

Integer filter.

### `MMC_FILTER_NOVALUE:0x8000`

When used by the
[IHeaderCtrl2::SetColumnFilter](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iheaderctrl2-setcolumnfilter) method, the snap-in sets the flag to clear the column filter.

When used by the
[IHeaderCtrl2::GetColumnFilter](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iheaderctrl2-getcolumnfilter) method, the flag is set to indicate that the column filter is empty.

## Remarks

The **MMC_FILTER_NOVALUE** enumerator value is not a filter type, but a flag that can be OR'd with a filter type. For example, to set a string type filter with no default value, you set the filter type to the following: `MMC_STRING_FILTER | MMC_FILTER_NOVALUE`.

When reading filter data, if no value has been entered by the snap-in or the user, the return type will be the filter type OR'd with **MMC_FILTER_NOVALUE**.

## See also

[IHeaderCtrl2::GetColumnFilter](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iheaderctrl2-getcolumnfilter)

[IHeaderCtrl2::SetColumnFilter](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iheaderctrl2-setcolumnfilter)