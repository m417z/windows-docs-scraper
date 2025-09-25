# IShellFolderView::RemoveObject

## Description

[**RemoveObject** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Removes an item from the view.

## Parameters

### `pidl` [in, optional]

Type: **PUITEMID_CHILD**

A pointer to the item to remove from the view. This value can be **NULL**. When using the system folder view object (DefView) under Windows XP and Windows Vista, a **NULL** value results in the removal of all objects from the view.

### `puItem` [out]

Type: **UINT***

When this method returns, contains a pointer to the index position of the removed item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Items removed through this method can be readded to the view by the data source at any time.