# IFolderView::GetSelectionMarkedItem

## Description

Gets the index of an item in the folder's view which has been marked by using the SVSI_SELECTIONMARK in [IFolderView::SelectItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-selectitem).

## Parameters

### `piItem` [out]

Type: **int***

A pointer to the index of the marked item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview)

[IFolderView::SelectItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-selectitem)