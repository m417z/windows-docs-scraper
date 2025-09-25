# IColumnData::GetColumnConfigData

## Description

The **IColumnData::GetColumnConfigData** method enables a snap-in to retrieve the current width, order, and hidden status of each column in a column set that is stored in memory by MMC.

## Parameters

### `pColID` [in]

A pointer to an
[SColumnSetID](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-scolumnsetid) structure that holds the ID of the column set whose data is to be retrieved.

### `ppColSetData` [out]

A pointer to a pointer to an
[MMC_COLUMN_SET_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_column_set_data) structure that will hold the retrieved column data.

## Return value

This method can return one of these values.

## Remarks

Suppose the user selects a scope item and then modifies the column configuration data of the list view of the selected item. If the snap-in calls **IColumnData::GetColumnConfigData** to retrieve that list view's column configuration data, the method will return the new data, regardless of whether or not the user has deselected the item.

The
**MMC_COLUMN_SET_DATA** structure and its array of
**MMC_COLUMN_DATA** structures are allocated as one contiguous memory block by MMC during calls to
**GetColumnConfigData**. The snap-in must call **CoTaskMemFree** with the given pointer to
**MMC_COLUMN_SET_DATA**. This frees the entire memory block.

All data set and retrieved by the methods of the
**IColumnData** interface is persisted by MMC in memory, and not in a stream or storage medium. This data is saved to an .MSC console file only when the user clicks the
**Save** menu command.

## See also

[IColumnData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icolumndata)

[Using IColumnData](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-icolumndata)