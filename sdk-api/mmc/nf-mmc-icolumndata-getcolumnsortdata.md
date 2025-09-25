# IColumnData::GetColumnSortData

## Description

The **IColumnData::GetColumnSortData** method enables a snap-in to retrieve from memory the sorted column and sorting direction for columns in a column set.

## Parameters

### `pColID` [in]

A pointer to an
[SColumnSetID](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-scolumnsetid) structure that contains the ID of the column set whose sort data is to be retrieved.

### `ppColSortData` [out]

A pointer to a pointer to an
[MMC_SORT_SET_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_sort_set_data) structure that will contain the column sort data of the column set.

## Return value

This method can return one of these values.

## Remarks

If the user selects a scope item and then modifies the sort data of the list view of the selected item. If the snap-in calls **IColumnData::GetColumnSortData** to retrieve the same sort data, the method will return the new data, regardless of whether the user has deselected the item or not.

The
[MMC_SORT_SET_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_sort_set_data) structure and its array of
[MMC_SORT_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_sort_data) structures are allocated as one contiguous memory block by MMC during calls to
GetColumnSortData. The snap-in must call CoTaskMemFree with the given pointer to
**MMC_SORT_SET_DATA**. This frees the entire memory block.

All data set and retrieved by the methods of the
[IColumnData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icolumndata) interface is persisted by MMC in memory, and not in a stream or storage medium. This data is persisted to an .msc console file only when the user chooses the
**Save** menu command.

## See also

[IColumnData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icolumndata)

[Using IColumnData](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-icolumndata)