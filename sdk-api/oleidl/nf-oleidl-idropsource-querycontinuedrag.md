# IDropSource::QueryContinueDrag

## Description

Determines whether a drag-and-drop operation should be continued, canceled, or completed. You do not call this method directly. The OLE [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function calls this method during a drag-and-drop operation.

## Parameters

### `fEscapePressed` [in]

Indicates whether the Esc key has been pressed since the previous call to **QueryContinueDrag** or to [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) if this is the first call to **QueryContinueDrag**. A **TRUE** value indicates the end user has pressed the escape key; a **FALSE** value indicates it has not been pressed.

### `grfKeyState` [in]

The current state of the keyboard modifier keys on the keyboard. Possible values can be a combination of any of the flags MK_CONTROL, MK_SHIFT, MK_ALT, MK_BUTTON, MK_LBUTTON, MK_MBUTTON, and MK_RBUTTON.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The drag operation should continue. This result occurs if no errors are detected, the mouse button starting the drag-and-drop operation has not been released, and the Esc key has not been detected. |
| **DRAGDROP_S_DROP** | The drop operation should occur completing the drag operation. This result occurs if *grfKeyState* indicates that the key that started the drag-and-drop operation has been released. |
| **DRAGDROP_S_CANCEL** | The drag operation should be canceled with no drop operation occurring. This result occurs if *fEscapePressed* is **TRUE**, indicating the Esc key has been pressed. |

## Remarks

The [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function calls **QueryContinueDrag** whenever it detects a change in the keyboard or mouse button state during a drag-and-drop operation. **QueryContinueDrag** must determine whether the drag-and-drop operation should be continued, canceled, or completed based on the contents of the parameters *grfKeyState* and *fEscapePressed*.

## See also

[DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop)

[IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource)