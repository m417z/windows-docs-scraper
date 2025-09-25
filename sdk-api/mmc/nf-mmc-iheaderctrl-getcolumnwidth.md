# IHeaderCtrl::GetColumnWidth

## Description

Retrieves the width, in pixels, of the column.

## Parameters

### `nCol` [in]

A zero-based index of the column from which the width is to be retrieved.

### `pWidth` [out]

A pointer to width, in pixels, of the column. This parameter must not be **NULL**.

## Return value

This method can return one of these values.

## Remarks

This method can be called successfully even if items are already in the list.

If the column is currently hidden,
GetColumnWidth returns 0 (zero) as the column width. However, because a column can have a (0) zero width without being hidden, a return value of (0) zero does not mean that the column is hidden. Therefore, the snap-in should call
[IColumnData::GetColumnConfigData](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icolumndata-getcolumnconfigdata) to identify which columns are hidden.

## See also

[IHeaderCtrl](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iheaderctrl)