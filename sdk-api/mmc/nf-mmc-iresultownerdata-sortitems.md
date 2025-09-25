# IResultOwnerData::SortItems

## Description

The **IResultOwnerData::SortItems** method sorts the items of a virtual result list.

## Parameters

### `nColumn` [in]

An index of the column header clicked.

### `dwSortOptions` [in]

The sort options to be used during the sort operation. This value can be a combination of the following:

#### RSI_DESCENDING = 0x0001

The sort should be in descending order. The default is to sort in ascending order.

#### RSI_NOSORTICON = 0x0002

Instructs MMC to remove the sort arrow icon. This option is useful when the snap-in performs a custom sort operation.

### `lUserParam` [in]

A user parameter passed in an
[IResultData::Sort](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-sort) call, **NULL** if the user initiated the sort.

## Return value

This method can return one of these values.

## Remarks

Because the snap-in maintains all the item data storage for a virtual list, the list does not support sorting. The console calls this function when the user clicks the header item of a virtual list or when the snap-in calls
[IResultData::Sort](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-sort).

MMC calls **IResultOwnerData::SortItems** with the same sort options that were passed by the snap-in in the call to [IResultData::Sort](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-sort).

## See also

[IResultData::Sort](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-sort)