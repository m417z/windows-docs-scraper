# IResultDataCompare::Compare

## Description

The **IResultDataCompare::Compare** method provides a way for a primary snap-in to compare cookies for the purpose of sorting the result items that it inserts in the result pane.

The **IResultDataCompare::Compare** method cannot be used for scope items. However, this functionality is provided by the
[IResultDataCompareEx::Compare](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdatacompareex-compare) method.

## Parameters

### `lUserParam` [in]

A value that specifies user-provided information that is passed into
[IResultData::Sort](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-sort). MMC does not interpret this parameter.

### `cookieA` [in]

The unique identifier of the first result item object to be compared as part of the sorting operation.

### `cookieB` [in]

The unique identifier of the second result item object to be compared as part of the sorting operation.

### `pnResult` [in, out]

As an in parameter, the argument contains the column that is sorted. As an out parameter, the value of the argument should be:

* -1 if item 1 < item 2
* zero (0) if item 1 == item 2
* 1 if item 1 > item 2

## Return value

This method can return one of these values.

## Remarks

Compare provides a mechanism for determining the sort order of result item objects appearing in the result pane. The built-in sort provided by MMC only uses the C run-time library string-compare function to compare the data. If this interface is implemented, it is used for all comparisons.

The comparison should be based on an ascending sort order. If the user toggles the standard result view header, the console complements the compare results, which results in a descending sort order.

This
IResultDataCompare interface is not called for virtual list sorting. Because the snap-in maintains all the item data storage for a virtual list, the snap-in must sort the items itself. A snap-in must implement the
[IResultOwnerData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultownerdata) interface to provide sorting for virtual lists.

## See also

[IResultData::Sort](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-sort)

[IResultOwnerData::SortItems](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultownerdata-sortitems)