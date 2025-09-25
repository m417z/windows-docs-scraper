# IDropTarget::Drop

## Description

Incorporates the source data into the target window, removes target feedback, and releases the data object.

## Parameters

### `pDataObj` [in]

A pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object being transferred in the drag-and-drop operation.

### `grfKeyState` [in]

The current state of the keyboard modifier keys on the keyboard. Possible values can be a combination of any of the flags MK_CONTROL, MK_SHIFT, MK_ALT, MK_BUTTON, MK_LBUTTON, MK_MBUTTON, and MK_RBUTTON.

### `pt` [in]

A [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure containing the current cursor coordinates in screen coordinates.

### `pdwEffect` [in, out]

On input, pointer to the value of the *pdwEffect* parameter of the [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function. On return, must contain one of the [DROPEFFECT](https://learn.microsoft.com/windows/desktop/com/dropeffect-constants) flags, which indicates what the result of the drop operation would be.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **DRAGDROP_S_CANCEL** | The OLE drag-and-drop operation was canceled. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_INVALIDARG** | The *pdwEffect* parameter is not valid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

You do not call this method directly. The [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function calls this method when the user completes the drag-and-drop operation.

In implementing **Drop**, you must incorporate the data object into the target. Use the formats available in [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject), available through *pDataObj*, along with the current state of the modifier keys to determine how the data is to be incorporated, such as linking or embedding.

In addition to incorporating the data, you must also clean up as you do in the [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave) method:

* Remove any target feedback that is currently displayed.
* Release any references to the data object.

You also pass the effect of this operation back to the source application through [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop), so the source application can clean up after the drag-and-drop operation is complete:

* Remove any source feedback that is being displayed.
* Make any necessary changes to the data, such as removing the data if the operation was a move.

## See also

[DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop)

[IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource)

[IDropSourceNotify](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsourcenotify)

[IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget)

[RegisterDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-registerdragdrop)

[RevokeDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-revokedragdrop)