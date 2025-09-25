# IDropSource::GiveFeedback

## Description

Enables a source application to give visual feedback to the end user during a drag-and-drop operation by providing the [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function with an enumeration value specifying the visual effect.

## Parameters

### `dwEffect` [in]

The [DROPEFFECT](https://learn.microsoft.com/windows/desktop/com/dropeffect-constants) value returned by the most recent call to [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter), [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover), or [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave).

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **DRAGDROP_S_USEDEFAULTCURSORS** | Indicates successful completion of the method, and requests OLE to update the cursor using the OLE-provided default cursors. |

## Remarks

When your application detects that the user has started a drag-and-drop operation, it should call the [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function. **DoDragDrop** enters a loop, calling [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) when the mouse first enters a drop target window, [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover) when the mouse changes its position within the target window, and [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave) when the mouse leaves the target window.

For every call to either [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) or [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover), [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) calls **IDropSource::GiveFeedback**, passing it the DROPEFFECT value returned from the drop target call.

[DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) calls [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave) when the mouse has left the target window. Then, **DoDragDrop** calls **IDropSource::GiveFeedback** and passes the DROPEFFECT_NONE value in the *dwEffect* parameter.

The *dwEffect* parameter can include DROPEFFECT_SCROLL, indicating that the source should put up the drag-scrolling variation of the appropriate pointer.

### Notes to Implementers

This function is called frequently during the [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) loop, so you can gain performance advantages if you optimize your implementation as much as possible.

**IDropSource::GiveFeedback** is responsible for changing the cursor shape or for changing the highlighted source based on the value of the *dwEffect* parameter. If you are using default cursors, you can return DRAGDROP_S_USEDEFAULTCURSORS, which causes OLE to update the cursor for you, using its defaults.

## See also

[DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop)

[IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource)

[IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget)