# IShellFolderView::IsBkDropTarget

## Description

[**IsBkDropTarget** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Checks if the target of a drag-and-drop operation is the background of the view.

## Parameters

### `pDropTarget` [in, optional]

Type: **[IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget)***

A pointer to the target of the drag-and-drop operation.

## Return value

Type: **HRESULT**

Returns S_OK if the target of the drag-and-drop operation is to the background of the view, S_FALSE otherwise.