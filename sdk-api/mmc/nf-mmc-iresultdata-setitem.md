# IResultData::SetItem

## Description

The **IResultData::SetItem** method enables the snap-in to set a single item in the result pane.

## Parameters

### `item` [in]

A pointer to a
[RESULTDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-resultdataitem) structure that contains information about the item to be changed.

## Return value

This method can return one of these values.

## Remarks

The itemID member of the structure pointed to by the item parameter should be set to refer to the item or subitem to be changed in the list. The mask and all appropriate associated fields in the
[RESULTDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-resultdataitem) structure should be filled out with the preferred changes. The nCol member should be set to 0 (zero) because it is the only column in which anything can be set or obtained. The str member of
**RESULTDATAITEM** should always be set to MMC_CALLBACK.

This method does not support virtual lists.

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)

[IResultData::GetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-getitem)