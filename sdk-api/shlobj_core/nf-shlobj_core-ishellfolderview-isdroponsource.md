# IShellFolderView::IsDropOnSource

## Description

[This method has been deprecated. Use [IFolderView2::IsMoveInSameFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview2-ismoveinsamefolder) instead.]

Checks whether the destination of the current drag-and-drop or cut-and-paste operation is the same as the source.

## Parameters

### `pDropTarget` [in, optional]

Type: **[IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget)***

A pointer to a destination drop target object.

## Return value

Type: **HRESULT**

Returns **S_OK** if the destination is the same as the source.