# IResultDataCompareEx::Compare

## Description

The **IResultDataCompareEx::Compare** method provides a way for a primary snap-in to compare items for the purpose of sorting the scope and result items that it inserts in the result pane.

## Parameters

### `prdc` [in]

A pointer to an
[RDCOMPARE](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-rdcompare) structure that holds information about the items being compared and which column in the result pane list view is being sorted.

### `pnResult` [out]

The snap-in should set pnResult to the result of the comparison:

* Any negative integer if item 1 < item 2
* Zero (0) if item 1 == item 2
* Any positive integer if item 1 > item 2

## Return value

This method can return one of these values.

## Remarks

Compare provides a mechanism for determining the sort order of scope and result item objects appearing in the result pane. The built-in sort provided by MMC only uses the C run-time library's string-compare function to compare the data. If this interface is implemented, it is used for all comparisons.

The comparison should be based on an ascending sort order. If the user toggles the standard result view header, the console complements the compare results, which results in a descending sort order.

The
IResultDataCompareEx interface is not called for virtual list sorting. This is because the snap-in maintains all the item data storage for a virtual list, the snap-in must sort the items itself. A snap-in must implement the
[IResultOwnerData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultownerdata) interface to provide sorting for virtual lists.