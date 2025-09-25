# IFolderView::ItemCount

## Description

Gets the number of items in the folder. This can be the number of all items, or a subset such as the number of selected items.

## Parameters

### `uFlags` [in]

Type: **UINT**

Flags from the [_SVGIO](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_svgio) enumeration that limit the count to certain types of items.

### `pcItems` [out]

Type: **int***

Pointer to an integer that receives the number of items (files and folders) displayed in the folder view.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.