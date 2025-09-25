# OleSetClipboard function

## Description

Places a pointer to a specific data object onto the clipboard. This makes the data object accessible to the [OleGetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetclipboard) function.

## Parameters

### `pDataObj` [in]

Pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object from which the data to be placed on the clipboard can be obtained. This parameter can be **NULL**; in which case the clipboard is emptied.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **CLIPBRD_E_CANT_OPEN** | The [OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard) function used within [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) failed. |
| **CLIPBRD_E_CANT_EMPTY** | The [EmptyClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-emptyclipboard) function used within [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) failed. |
| **CLIPBRD_E_CANT_CLOSE** | The [CloseClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closeclipboard) function used within [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) failed. |
| **CLIPBRD_E_CANT_SET** | The [SetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboarddata) function used within [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) failed. |

## Remarks

If you are writing an application that can act as the source of a clipboard operation, you must do the following:

* Create a data object (on which is the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface) for the data being copied or cut to the clipboard. This object should be the same object used in OLE drag-and-drop operations.
* Call **OleSetClipboard** to place the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) pointer onto the clipboard, so it is accessible to the [OleGetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetclipboard) function. **OleSetClipboard** also calls the [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on your data object.
* If you wish, release the data object after you have placed it on the clipboard to free the [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) counter in your application.
* If the user is cutting data (deleting it from the document and putting it on to the clipboard), remove the data from the document.

All formats are offered on the clipboard using delayed rendering (the clipboard contains only a pointer to the data object unless a call to [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) renders the data onto the clipboard). The formats necessary for OLE 1 compatibility are synthesized from the OLE 2 formats that are present and are also put on the clipboard.

The **OleSetClipboard** function assigns ownership of the clipboard to an internal OLE window handle. The reference count of the data object is increased by 1, to enable delayed rendering. The reference count is decreased by a call to the [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) function or by a subsequent call to **OleSetClipboard** specifying **NULL** as the parameter value (which clears the clipboard).

When an application opens the clipboard (either directly or indirectly by calling the [OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard) function), the clipboard cannot be used by any other application until it is closed. If the clipboard is currently open by another application, **OleSetClipboard** fails. The internal OLE window handle satisfies WM_RENDERFORMAT messages by delegating them to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) implementation on the data object that is on the clipboard.

Specifying **NULL** as the parameter value for **OleSetClipboard** empties the current clipboard. If the contents of the clipboard are the result of a previous **OleSetClipboard** call and the clipboard has been released, the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) pointer that was passed to the previous call is released. The clipboard owner should use this as a signal that the data it previously offered is no longer on the clipboard.

If you need to leave the data on the clipboard after your application is closed, you should call [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) rather than calling **OleSetClipboard** with a **NULL** parameter value.

## See also

[OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard)

[OleGetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetclipboard)

[OleIsCurrentClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleiscurrentclipboard)