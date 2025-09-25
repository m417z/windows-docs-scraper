# IFolderView::GetItemPosition

## Description

Gets the position of an item in the folder's view.

## Parameters

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) interface.

### `ppt` [out]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a structure that receives the position of the item's upper-left corner.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.