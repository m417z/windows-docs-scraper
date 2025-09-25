# IColumnData::SetColumnSortData

## Description

The **IColumnData::SetColumnSortData** method enables a snap-in to set the sorted column and sorting direction for columns in a column set.

## Parameters

### `pColID` [in]

A pointer to an
[SColumnSetID](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-scolumnsetid) structure that contains the column set ID of the column set whose sort data is to be set.

### `pColSortData` [in]

A pointer to an
[MMC_SORT_SET_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_sort_set_data) structure that contains the column sort data of the column set.

## Return value

This method can return one of these values.

## Remarks

If the user selects a scope item, and the snap-in then calls **IColumnData::SetColumnSortData** to modify the sort data of the list view of the selected item. MMC will apply the changes to the list view only after the user has deselected and then reselected the item. Be aware that MMC also applies the changes to all column sets with the same ID, so if the user selects a different item with the same column set ID, MMC will also apply the persisted data to it.

MMC 1.2 supports only single-column sorting, which is why
SetColumnSortData returns **E_FAIL** when the number of sort columns is greater than 1.

All data set and retrieved by the methods of the
[IColumnData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icolumndata) interface is persisted by MMC in memory, and not in a stream or storage medium. This data is persisted to an .msc console file only when the user chooses the
**Save** menu command.

## See also

[IColumnData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icolumndata)

[Using IColumnData](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-icolumndata)