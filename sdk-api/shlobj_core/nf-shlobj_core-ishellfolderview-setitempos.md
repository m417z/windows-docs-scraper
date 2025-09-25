# IShellFolderView::SetItemPos

## Description

[This method has been deprecated. Use [IFolderView::SelectAndPositionItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-selectandpositionitems) instead.]

Sets the position of the given item.

## Parameters

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A PIDL that corresponds to the item for which the position is being set.

### `ppt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a structure that contains the new coordinates of the item relative to the ListView contained in the view.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.