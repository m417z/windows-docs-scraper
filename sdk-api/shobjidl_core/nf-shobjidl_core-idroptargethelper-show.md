# IDropTargetHelper::Show

## Description

Notifies the drag-image manager to show or hide the drag image.

## Parameters

### `fShow` [in]

Type: **BOOL**

A boolean value that is set to **TRUE** to show the drag image, and **FALSE** to hide it.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error value otherwise.

## Remarks

This method is used when dragging over a target window in a low color-depth video mode. It allows the target to notify the drag-image manager to hide the drag image while it is painting the window. While you are painting a window that is currently being dragged over, hide the drag image by calling **Show** with *fShow* set to **FALSE**. Once the window has been painted, display the drag image again by calling **Show** with *fShow* set to **TRUE**.

## See also

[IDropTargetHelper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idroptargethelper)