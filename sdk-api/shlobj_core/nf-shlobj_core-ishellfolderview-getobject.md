# IShellFolderView::GetObject

## Description

[**GetObject** is no longer available for use as of Windows Vista. Instead, use [IFolderView::Item](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-item).]

Gets an item from the view.

## Parameters

### `ppidl` [out]

Type: **PITEMID_CHILD***

When this method returns, contains the address of a pointer to the item at the given index.

### `uItem`

Type: **UINT**

The index of the item in the view to get.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.