# IHeaderCtrl::SetColumnWidth

## Description

Sets the width, in pixels, of a specific column.

## Parameters

### `nCol` [in]

A zero-based index that specifies the location of the column relative to other columns in the result pane.

### `nWidth` [in]

A value that specifies the width of the column. This value must be in pixels, or it can be the following value:

#### MMCLV_AUTO

MMC automatically determines the width of the column based on the width of the text in the column title.

## Return value

This method can return one of these values.

## Remarks

MMC does not persist in memory any changes made to a column set due to the action of **IHeaderCtrl::SetColumnWidth**, so snap-ins must update persisted column configuration data after modifying the width of columns in a column set. For more information, see
[IHeaderCtrl2 and Column Persistence](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/iheaderctrl2-and-column-persistence).

The HIDE_COLUMN flag for the nWidth parameter is not supported for
SetColumnWidth. If the snap-in must hide the column, it must call [IConsole::SelectScopeItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsole-selectscopeitem) to reselect the scope item and then in the resulting call to the snap-in's [MMCN_SHOW](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-show) notification handler, it must use nWidth=HIDE_COLUMN when inserting the column (in the call to [IHeaderCtrl::InsertColumn](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iheaderctrl-insertcolumn)).

## See also

[IHeaderCtrl](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iheaderctrl)

[IHeaderCtrl2 and Column Persistence](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/iheaderctrl2-and-column-persistence)