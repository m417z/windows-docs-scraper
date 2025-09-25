# DoDragDrop function

## Description

Carries out an OLE drag and drop operation.

**Note** You must call [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) before calling this function.

## Parameters

### `pDataObj` [in]

Pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on a data object that contains the data being dragged.

### `pDropSource` [in]

Pointer to an implementation of the [IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource) interface, which is used to communicate with the source during the drag operation.

### `dwOKEffects` [in]

Effects the source allows in the OLE drag-and-drop operation. Most significant is whether it permits a move. The *dwOKEffect* and *pdwEffect* parameters obtain values from the [DROPEFFECT](https://learn.microsoft.com/windows/desktop/com/dropeffect-constants) enumeration. For a list of values, see **DROPEFFECT**.

### `pdwEffect` [out]

 Pointer to a value that indicates how the OLE drag-and-drop operation affected the source data. The *pdwEffect* parameter is set only if the operation is not canceled.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **DRAGDROP_S_DROP** | The OLE drag-and-drop operation was successful. |
| **DRAGDROP_S_CANCEL** | The OLE drag-and-drop operation was canceled. |
| **E_UNSPEC** | Unexpected error occurred. |

## Remarks

If you are developing an application that can act as a data source for an OLE drag-and-drop operation, you must call **DoDragDrop** when you detect that the user has started an OLE drag-and-drop operation.

The **DoDragDrop** function enters a loop in which it calls various methods in the [IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource) and [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interfaces. (For a successful drag-and-drop operation, the application acting as the data source must also implement **IDropSource**, while the target application must implement **IDropTarget**.)

1. The **DoDragDrop** function determines the window under the current cursor location. It then checks to see if this window is a valid drop target.
2. If the window is a valid drop target, **DoDragDrop** calls [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter). This method supplies an effect code indicating what would happen if the drop actually occurred. For a list of valid drop effects, see the [DROPEFFECT](https://learn.microsoft.com/windows/desktop/com/dropeffect-constants) enumeration.
3. **DoDragDrop** calls [IDropSource::GiveFeedback](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idropsource-givefeedback) with the effect code so that the drop source interface can provide appropriate visual feedback to the user. The *pDropSource* pointer passed into **DoDragDrop** specifies the appropriate [IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource) interface.
4. **DoDragDrop** tracks mouse cursor movements and changes in the keyboard or mouse button state.

   * If the user moves out of a window, **DoDragDrop** calls [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave).
   * If the mouse enters another window, **DoDragDrop** determines if that window is a valid drop target and then calls [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) for that window.
   * If the mouse moves but stays within the same window, **DoDragDrop** calls [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover).
5. If there is a change in the keyboard or mouse button state, **DoDragDrop** calls [IDropSource::QueryContinueDrag](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idropsource-querycontinuedrag) and determines whether to continue the drag, to drop the data, or to cancel the operation based on the return value.

   * If the return value is S_OK, **DoDragDrop** first calls [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover) to continue the operation. This method returns a new effect value and **DoDragDrop** then calls [IDropSource::GiveFeedback](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idropsource-givefeedback) with the new effect so appropriate visual feedback can be set. For a list of valid drop effects, see the [DROPEFFECT](https://learn.microsoft.com/windows/desktop/com/dropeffect-constants) enumeration. **IDropTarget::DragOver** and **IDropSource::GiveFeedback** are paired so that as the mouse moves across the drop target, the user is given the most up-to-date feedback on the mouse's position.
   * If the return value is DRAGDROP_S_DROP, **DoDragDrop** calls [IDropTarget::Drop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop). The **DoDragDrop** function returns the last effect code to the source, so the source application can perform the appropriate operation on the source data, for example, cut the data if the operation was a move.
   * If the return value is DRAGDROP_S_CANCEL, the **DoDragDrop** function calls [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave).

**DoDragDrop** does not support invoking drag and drop support when you handle touch or pen input.

To support touch or pen input, do not call **DoDragDrop** from your touch handler. Instead, call **DoDragDrop** from your handler for those mouse messages that the system synthesizes upon touch input.

The application can identify synthesized messages by calling the [GetMessageExtraInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessageextrainfo) function. For more information about using **GetMessageExtraInfo** to distinguish between mouse input and Windows Touch input, see [Troubleshooting Applications](https://learn.microsoft.com/windows/desktop/wintouch/troubleshooting-applications).

## See also

[IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource)