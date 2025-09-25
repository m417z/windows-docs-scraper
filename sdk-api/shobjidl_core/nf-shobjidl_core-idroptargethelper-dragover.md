# IDropTargetHelper::DragOver

## Description

Notifies the drag-image manager that the drop target's [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover) method has been called.

## Parameters

### `ppt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

The [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure pointer that was received in the [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover) method's
*pt* parameter.

### `dwEffect` [in]

Type: **DWORD**

The value pointed to by the [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover) method's
*pdwEffect* parameter.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error value otherwise.

## Remarks

This method is called by a drop target when its [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover) method is called. It notifies the drag-image manager that the cursor position has changed and provides it with the information needed to display the drag image.

## See also

[IDropTargetHelper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idroptargethelper)