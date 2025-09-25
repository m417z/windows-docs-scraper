# IDropTarget::DragOver

## Description

Provides target feedback to the user and communicates the drop's effect to the [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function so it can communicate the effect of the drop back to the source.

## Parameters

### `grfKeyState` [in]

The current state of the keyboard modifier keys on the keyboard. Valid values can be a combination of any of the flags MK_CONTROL, MK_SHIFT, MK_ALT, MK_BUTTON, MK_LBUTTON, MK_MBUTTON, and MK_RBUTTON.

### `pt` [in]

A [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure containing the current cursor coordinates in screen coordinates.

### `pdwEffect` [in, out]

On input, pointer to the value of the *pdwEffect* parameter of the [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function. On return, must contain one of the [DROPEFFECT](https://learn.microsoft.com/windows/desktop/com/dropeffect-constants) flags, which indicates what the result of the drop operation would be.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_INVALIDARG** | The *pdwEffect* value is not valid. |
| **E_OUTOFMEMORY** | There was insufficient memory available for this operation. |

## Remarks

You do not call **DragOver** directly. The [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function calls this method each time the user moves the mouse across a given target window. **DoDragDrop** exits the loop if the drag-and-drop operation is canceled, if the user drags the mouse out of the target window, or if the drop is completed.

In implementing **IDropTarget::DragOver**, you must provide features similar to those in [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter). You must determine the effect of dropping the data on the target by examining the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) defining the data object's formats and medium, along with the state of the modifier keys. The mouse position may also play a role in determining the effect of a drop. The following modifier keys affect the result of the drop.

| Key Combination | User-Visible Feedback | Drop Effect |
| --- | --- | --- |
| CTRL + SHIFT | = | DROPEFFECT_LINK |
| CTRL | + | DROPEFFECT_COPY |
| No keys or SHIFT | None | DROPEFFECT_MOVE |

You communicate the effect of the drop back to the source through [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) in *pdwEffect*. The **DoDragDrop** function then calls [IDropSource::GiveFeedback](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idropsource-givefeedback) so the source application can display the appropriate visual feedback to the user.

On entry to **IDropTarget::DragOver**, the *pdwEffect* parameter must be set to the allowed effects passed to the *pdwOkEffect* parameter of the [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function. The **IDropTarget::DragOver** method must be able to choose one of these effects or disable the drop.

Upon return, *pdwEffect* is set to one of the DROPEFFECT flags. This value is then passed to the *pdwEffect* parameter of [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop). Reasonable values are DROPEFFECT_COPY to copy the dragged data to the target, DROPEFFECT_LINK to create a link to the source data, or DROPEFFECT_MOVE to allow the dragged data to be permanently moved from the source application to the target.

You may also wish to provide appropriate visual feedback in the target window. There may be some target feedback already displayed from a previous call to **IDropTarget::DragOver** or from the initial [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter). If this feedback is no longer appropriate, you should remove it.

For efficiency reasons, a data object is not passed in **IDropTarget::DragOver**. The data object passed in the most recent call to [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) is available and can be used.

When **IDropTarget::DragOver** has completed its operation, the [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function calls [IDropSource::GiveFeedback](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idropsource-givefeedback) so the source application can display the appropriate visual feedback to the user.

### Notes to Implementers

This function is called frequently during the [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) loop so it makes sense to optimize your implementation of the **DragOver** method as much as possible.

## See also

[DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop)

[IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource)

[IDropSourceNotify](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsourcenotify)

[IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget)

[RegisterDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-registerdragdrop)

[RevokeDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-revokedragdrop)