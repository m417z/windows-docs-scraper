# IResultData::DeleteItem

## Description

The **IResultData::DeleteItem** method enables the snap-in to delete a single item in the result view pane.

## Parameters

### `itemID` [in]

A value that specifies the unique ID of the item to be deleted. When applied to virtual lists, pass the item index instead of the itemID.

### `nCol` [in]

Not used. Must be zero.

## Return value

This method can return one of these values.

## Remarks

DeleteItem removes an item identified by itemID and nCol. If nCol does not equal zero, the subitem identified by itemID and nCol is cleared of all information. If nCol is equal to zero, the item identified by itemID and all of its subitems are deleted and removed from the list. If a subitem is deleted, itemID remains a valid identifier. However, if the main item is deleted, itemID should be destroyed or released. The same ID can be reassigned by the console to any newly inserted items.

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)