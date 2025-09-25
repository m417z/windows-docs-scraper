# IDropTargetHelper::DragLeave

## Description

Notifies the drag-image manager that the drop target's [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave) method has been called.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error value otherwise.

## Remarks

This method is called by a drop target when its [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave) method is called. It notifies the drag-image manager that the cursor has left the drop target.

## See also

[IDropTargetHelper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idroptargethelper)