# IFolderView::Item

## Description

Gets the identifier of a specific item in the folder view, by index.

## Parameters

### `iItemIndex` [in]

Type: **int**

The index of the item in the view.

### `ppidl` [out]

Type: **PITEMID_CHILD***

The address of a pointer to a PIDL containing the item's identifier information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When no longer needed, the PIDL should be freed by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

## See also

[IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview)

[IFolderView::Items](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-items)