# IResultData::UpdateItem

## Description

The **IResultData::UpdateItem** method causes a specified item in the result pane to be redrawn.

## Parameters

### `itemID` [in]

A value that specifies the unique identifier of the item to be redrawn in the result pane. When applied to virtual lists, pass the item index instead of the itemID.

## Return value

This method can return one of these values.

## Remarks

UpdateItem would typically be used to update a displayed item after changes were made to it by the user.

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)