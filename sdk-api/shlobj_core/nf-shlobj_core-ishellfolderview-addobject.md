# IShellFolderView::AddObject

## Description

[**AddObject** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Adds an item to the view.

## Parameters

### `pidl` [in]

Type: **PUITEMID_CHILD**

A pointer to an ItemID that specifies the item to add to the view.

### `puItem` [out]

Type: **UINT***

A pointer to a value that, when this method returns successfully, receives the index position of the added item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you immediately call [IShellFolderView::GetObject](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishellfolderview-getobject) with this index, you will get a copy of the ITEMID_CHILD that you added. However, the index position of an item may change over time, so code cannot trust that any specific index always returns the same ITEMID_CHILD.

Items added through this method can be removed from the view by the data source at any time.