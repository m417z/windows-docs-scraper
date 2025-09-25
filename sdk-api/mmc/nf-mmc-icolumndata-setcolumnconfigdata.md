# IColumnData::SetColumnConfigData

## Description

The **IColumnData::SetColumnConfigData** method enables a snap-in to set the persisted width, order, and hidden status of columns in a column set.

## Parameters

### `pColID` [in]

A pointer to an
[SColumnSetID](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-scolumnsetid) structure that contains the ID of the column set whose data is to be set.

### `pColSetData` [in]

A pointer to an
[MMC_COLUMN_SET_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_column_set_data) structure that contains the number of columns in the column set as well as the column data to be set.

## Return value

This method can return one of these values.

## Remarks

If the user selects a scope item, and the snap-in then calls **IColumnData::SetColumnConfigData** to modify the column configuration data of the list view of the selected item. MMC will apply the changes to the list view only after the user has deselected and then reselected the item. Be aware that MMC also applies the changes to all column sets with the same ID, so if the user selects a different item with the same column set ID, MMC will also apply the persisted data to it.

Calling
**IColumnData::SetColumnConfigData** clears the previously stored sort information and column configuration information.

## See also

[IColumnData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icolumndata)

[Using IColumnData](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-icolumndata)