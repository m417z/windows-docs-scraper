# IFolderView::SelectItem

## Description

Selects an item in the folder's view.

## Parameters

### `iItem` [in]

Type: **int**

The index of the item to select in the folder's view.

### `dwFlags` [in]

Type: **DWORD**

One of the [_SVSIF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_svsif) constants that specify the type of selection to apply.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview)

[IFolderView::GetSelectionMarkedItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-getselectionmarkeditem)

[IFolderView::SelectAndPositionItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-selectandpositionitems)

[SelectItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-selectitem)