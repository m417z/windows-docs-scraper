# IResultData::Sort

## Description

The **IResultData::Sort** method sorts all items in the result pane.

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

A value that specifies information determined by the user. This parameter can contain a variety of entries such as including sort order or context information.

## Return value

This method can return one of these values.

## Remarks

If your snap-in implements the
[IResultDataCompare](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdatacompare) or the
[IResultDataCompareEx](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdatacompareex) interface, MMC calls the interface's
Compare method to allow the snap-in to compare list items. Otherwise, MMC uses a default string-compare function.

There is no sorting function for a virtual list. To allow virtual list sorting the snap-in must implement the
[IResultOwnerData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultownerdata) interface. When **IResultData::Sort** is called, MMC forwards the call to
[IResultOwnerData::SortItems](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultownerdata-sortitems).

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)

[IResultDataCompare::Compare](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdatacompare-compare)

[IResultOwnerData::SortItems](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultownerdata-sortitems)