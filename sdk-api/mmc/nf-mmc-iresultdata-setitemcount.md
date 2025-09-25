# IResultData::SetItemCount

## Description

The **IResultData::SetItemCount** method sets the number of items in a virtual list.

## Parameters

### `nItemCount` [in]

The number of items that the control will contain.

### `dwOptions` [in]

Combination of the following flags:

#### MMCLV_UPDATE_NOINVALIDATEALL

Only repaint items added or removed at the bottom of the result pane. Set this flag only if items are removed or added at the bottom of the list.

#### MMCLV_UPDATE_NOSCROLL

Do not adjust the scroll bar on changed item count.

## Return value

This method can return one of these values.

## Remarks

The primary purpose of the
SetItemCount method is to populate virtual lists. Because items are not actually added to a virtual list, this is the way to notify the list how many virtual items exist.

**Note** Do not set the MMCLV_UPDATE_NOINVALIDATEALL flag when items are added or removed from the middle of the list; that is, when reindexing of the existing items is required. If you add or remove items in the middle of the list, setting the flag produces an incorrect update of the list.

The MMCLV_UPDATE_NOINVALIDATEALL flag should be used in cases where you are only adding and deleting from the end of the virtual list and you want to reduce the amount of redrawing. If you set this flag, MMC only calls [IComponent::GetDisplayInfo](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getdisplayinfo) on new items added to the result pane. Setting the flag tells MMC that none of the items are being renumbered. MMC redraws only the visible items that were added or deleted.

SetItemCount can be called for nonvirtual lists as well, but for a different purpose. When called for a nonvirtual list,
SetItemCount preallocates memory for the specified number of items. When adding a large number of items, this improves performance by reducing the number of memory allocation calls the list must do.

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)

[IResultOwnerData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultownerdata)