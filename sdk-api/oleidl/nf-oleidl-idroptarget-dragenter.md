# IDropTarget::DragEnter

## Description

Indicates whether a drop can be accepted, and, if so, the effect of the drop.

## Parameters

### `pDataObj` [in]

A pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object. This data object contains the data being transferred in the drag-and-drop operation. If the drop occurs, this data object will be incorporated into the target.

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
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_INVALIDARG** | The *pdwEffect* parameter is **NULL** on input. |
| **E_OUTOFMEMORY** | There was insufficient memory available for this operation. |

## Remarks

You do not call **DragEnter** directly; instead the [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function calls it to determine the effect of a drop the first time the user drags the mouse into the registered window of a drop target.

To implement **DragEnter**, you must determine whether the target can use the data in the source data object by checking three things:

* The format and medium specified by the data object
* The input value of *pdwEffect*
* The state of the modifier keys

To check the format and medium, use the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) pointer passed in the *pDataObject* parameter to call [IDataObject::EnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-enumformatetc) so you can enumerate the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures the source data object supports. Then call [IDataObject::QueryGetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-querygetdata) to determine whether the data object can render the data on the target by examining the formats and medium specified for the data object.

On entry to **IDropTarget::DragEnter**, the *pdwEffect* parameter is set to the effects given to the *pdwOkEffect* parameter of the [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) function. The **IDropTarget::DragEnter** method must choose one of these effects or disable the drop.

The following modifier keys affect the result of the drop.

| Key Combination | User-Visible Feedback | Drop Effect |
| --- | --- | --- |
| CTRL + SHIFT | = | DROPEFFECT_LINK |
| CTRL | + | DROPEFFECT_COPY |
| No keys or SHIFT | None | DROPEFFECT_MOVE |

On return, the method must write the effect, one of the DROPEFFECT flags, to the *pdwEffect* parameter. [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) then takes this parameter and writes it to its *pdwEffect* parameter. You communicate the effect of the drop back to the source through **DoDragDrop** in the *pdwEffect* parameter. The **DoDragDrop** function then calls [IDropSource::GiveFeedback](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idropsource-givefeedback) so that the source application can display the appropriate visual feedback to the user through the target window.

## See also

[DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter)

[IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource)

[IDropSourceNotify](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsourcenotify)

[IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget)

[RegisterDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-registerdragdrop)

[RevokeDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-revokedragdrop)