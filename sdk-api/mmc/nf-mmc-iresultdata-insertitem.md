# IResultData::InsertItem

## Description

The **IResultData::InsertItem** method enables the snap-in to add a single new item to the result pane view.

## Parameters

### `item` [in, out]

A pointer to a
[RESULTDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-resultdataitem) structure that contains information about the item to be added.

After the item is inserted, a unique identifier (an item ID) is assigned to it by MMC and returned through the **itemID** member of the structure pointed to by the item parameter. Be aware that the **itemID** value is the **HRESULTITEM** handle of the inserted item. The snap-in should store this value in order to later manipulate the inserted item by calling methods such as [IResultData::GetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-getitem).

If this identifier is not stored, it can be looked up using
[IResultData::FindItemByLParam](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-finditembylparam).

## Return value

This method can return one of these values.

## Remarks

The mask and all appropriate associated fields in the
[RESULTDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-resultdataitem) structure should be filled out. Subitems cannot be inserted but can be set. The **nCol** member of the item structure must therefore be zero.

The str member of
[RESULTDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-resultdataitem) must be set to **MMC_CALLBACK**.

After the item is inserted, a unique identifier (an item ID) is assigned to it by MMC and returned through the **itemID** member of the structure pointed to by the item parameter. Be aware that the **itemID** value is the **HRESULTITEM** handle of the inserted item. The snap-in should store this value in order to later manipulate the inserted item by calling methods such as [IResultData::GetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-getitem).

If this identifier is not stored, it can be identified using
[IResultData::FindItemByLParam](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-finditembylparam).

This method does not support virtual lists.

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)