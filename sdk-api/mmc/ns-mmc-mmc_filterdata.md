# MMC_FILTERDATA structure

## Description

The
MMC_FILTERDATA structure is introduced in MMC 1.2.

The
MMC_FILTERDATA structure is used by the
[IHeaderCtrl2::GetColumnFilter](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iheaderctrl2-getcolumnfilter) and
[IHeaderCtrl2::SetColumnFilter](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iheaderctrl2-setcolumnfilter) methods to retrieve and set the filter value of a column in a filtered list view.

## Members

### `pszText`

When a snap-in sets a text filter value, pszText points to the filter string to set and cchTextMax sets the maximum length of the filter string that the user can type into the filter field. When a snap-in reads a text filter value, pszText points to a buffer to receive the text and cchTextMax gives the length of the buffer.

### `cchTextMax`

For more information, see the description for pszText.

### `lValue`

When a snap-in sets a numeric filter value, lValue contains the filter value. The filter field converts the value to a string and places it in the filter control. When a snap-in reads a numeric filter value, the current filter value is converted to binary and returned in lValue.

## Remarks

A numeric filter value can be used when the column it is filtering has only numeric values rather than arbitrary text strings. The advantage of using a numeric filter is that the filter handles the conversion between the binary and text when setting and reading the filter value. Also the filter control only allows a user to type numeric characters into a numeric filter.

When handling a text filter, lValue is ignored. Similarly, when handling a numeric filter, pszText and cchTextMax are ignored.

For both setting and reading filter values, the snap-in owns the
MMC_FILTERDATA structure and any text buffer.