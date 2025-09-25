# IShellFolderView::GetSelectedCount

## Description

[**GetSelectedCount** is no longer available for use as of Windows Vista. Instead, use [IFolderView2::GetSelection](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview2-getselection).]

Gets the number of items in the view that are selected.

## Parameters

### `puSelected` [out]

Type: **UINT***

A pointer to a value that, when this method returns successfully, receives the number of selected items in the view.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.