# IDropTargetHelper::Drop

## Description

Notifies the drag-image manager that the drop target's [IDropTarget::Drop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop) method has been called.

## Parameters

### `pDataObject` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to the data object's [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface.

### `ppt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure pointer that was received in the [IDropTarget::Drop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop) method's
*pt* parameter.

### `dwEffect` [in]

Type: **DWORD**

The value pointed to by the [IDropTarget::Drop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop) method's
*pdwEffect* parameter.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error value otherwise.

## Remarks

This method is called by a drop target when its [IDropTarget::Drop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop) method is called. It notifies the drag-image manager that the object has been dropped, and provides it with the information needed to display the drag image.

## See also

[IDropTargetHelper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idroptargethelper)