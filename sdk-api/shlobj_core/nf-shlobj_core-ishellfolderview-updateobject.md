# IShellFolderView::UpdateObject

## Description

[**UpdateObject** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Replaces an item in a view with another item.

## Parameters

### `pidlOld` [in]

Type: **PUITEMID_CHILD**

The original item.

### `pidlNew` [in]

Type: **PUITEMID_CHILD**

The new item.

### `puItem` [out]

Type: **UINT***

When this method returns, contains a pointer to the index of the item that was replaced. You can use this value to call [IShellFolderView::GetObject](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishellfolderview-getobject) on later to get back the PITEMID_CHILD that you just added.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you immediately call [IShellFolderView::GetObject](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishellfolderview-getobject) with the index returned by *puItem*, you will get a copy of the ITEMID_CHILD that you added. However, the index position of an item may change over time, so code cannot trust that any specific index always returns the same ITEMID_CHILD.

Changes made through this method can be discarded in the view by the data source at any time.