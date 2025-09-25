# IHeaderCtrl2::SetColumnFilter

## Description

The **IHeaderCtrl2::SetColumnFilter** sets the filter value and its maximum character length for a specified column in a filtered list.

## Parameters

### `nColumn` [in]

A zero-based index that identifies the column for which the filter value and its maximum character length are to be set.

### `dwType` [in]

Filter type to apply to the specified column, taken from the
[MMC_FILTER_TYPE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_filter_type) enumeration.

### `pFilterData` [in]

A pointer to an
[MMC_FILTERDATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_filterdata) structure that holds the actual filter data.

## Return value

This method can return one of these values.

## Remarks

For both setting and reading filter values, the snap-in owns the
[MMC_FILTERDATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_filterdata) structure and any text buffer.

If the snap-in does not explicitly set the filter data for a column in a filtered list by calling **IHeaderCtrl2::SetColumnFilter**, the filter type defaults to MMC_STRING_FILTER with no default value for the filter (MMC_FILTER_NOVALUE). The default length of the filter is not documented by the Win32 header control, but it is of sufficient length for most likely user inputs. If the snap-in requires a specific length, it should call **IHeaderCtrl2::SetColumnFilter**.

## See also

[IHeaderCtrl2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iheaderctrl2)