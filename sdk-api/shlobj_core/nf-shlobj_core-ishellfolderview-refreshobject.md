# IShellFolderView::RefreshObject

## Description

[**RefreshObject** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Redraws the given item.

## Parameters

### `pidl` [in]

Type: **PUITEMID_CHILD**

The item to be redrawn.

### `puItem` [out]

Type: **UINT***

A pointer to a value that, when this method returns successfully, receives the index of the item that was redrawn. You can use this value to call [IShellFolderView::GetObject](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishellfolderview-getobject) to retrieve the PITEMID_CHILD that you just redrew.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you immediately call [IShellFolderView::GetObject](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishellfolderview-getobject) with the index returned by *puItem*, you will get a copy of the ITEMID_CHILD that you redrew. However, the index position of an item may change over time, so code cannot trust that any specific index always returns the same ITEMID_CHILD.