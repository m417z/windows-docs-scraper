# IHeaderCtrl2::GetColumnFilter

## Description

The **IHeaderCtrl2::GetColumnFilter** method retrieves the filter value set on the specified column.

## Parameters

### `nColumn` [in]

A zero-based index that identifies the column for which the filter value and its maximum character length are to be retrieved.

### `pdwType` [in, out]

A pointer to a variable of type **DWORD** that can take one of the possible filter values specified in the
[MMC_FILTER_TYPE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_filter_type) enumeration. The filter type for the specified column is placed in the address pointed to by *pdwType*.

### `pFilterData` [in, out]

A pointer to an
[MMC_FILTERDATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_filterdata) structure that holds the actual filter data.

## Return value

This method can return one of these values.

## Remarks

For both setting and reading filter values, the snap-in owns the
[MMC_FILTERDATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_filterdata) structure and any text buffer.

When reading a filter value, if the filter type specified by the snap-in does not match the current type, the **IHeaderCtrl2::GetColumnFilter** method will return **E_FAIL**. On receiving an **E_FAIL**, the values returned by the method are undefined.

## See also

[IHeaderCtrl2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iheaderctrl2)