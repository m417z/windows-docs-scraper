# IResultData::FindItemByLParam

## Description

The **IResultData::FindItemByLParam** method enables the snap-in to find an item or subitem based on its user-inserted lParam value.

## Parameters

### `lParam` [in]

A generic 32-bit value in which information can be stored.

### `pItemID` [out]

A pointer to an item identifier to hold the results of the search for the lParam value.

## Return value

This method can return one of these values.

## Remarks

FindItemByLParam searches for an item based on its lParam. The unique identifier (cookie) of the first item in the list with a matching lParam is returned in pItemID. If no item is found, the search returns S_FALSE.

This method does not support virtual lists.

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)