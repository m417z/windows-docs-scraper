# IDropTarget::DragLeave

## Description

Removes target feedback and releases the data object.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

You do not call this method directly. The [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function calls this method in either of the following cases:

* When the user drags the cursor out of a given target window.
* When the user cancels the current drag-and-drop operation.

To implement **IDropTarget::DragLeave**, you must remove any target feedback that is currently displayed. You must also release any references you hold to the data transfer object.

## See also

[DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop)

[IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource)

[IDropSourceNotify](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsourcenotify)

[IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget)

[RegisterDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-registerdragdrop)

[RevokeDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-revokedragdrop)