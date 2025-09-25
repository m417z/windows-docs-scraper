# IHeaderCtrl::DeleteColumn

## Description

Removes a column from the header of the result view.

## Parameters

### `nCol` [in]

A zero-based index that identifies the column to be removed.

## Return value

This method can return one of these values.

## Remarks

If a column is removed, all columns with indexes greater than the one removed are adjusted down by one.

MMC does not persist in memory any changes made to a column set due to the action of **IHeaderCtrl::DeleteColumn**, so snap-ins must update persisted column configuration data after deleting columns from a column set. For more information, see
[IHeaderCtrl2 and Column Persistence](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/iheaderctrl2-and-column-persistence).

### Notes to Callers

This method returns *E_FAIL* when an item has already been inserted into the result view.

## See also

[IHeaderCtrl](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iheaderctrl)

[IHeaderCtrl2 and Column Persistence](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/iheaderctrl2-and-column-persistence)