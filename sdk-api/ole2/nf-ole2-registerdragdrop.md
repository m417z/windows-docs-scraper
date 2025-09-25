## Description

Registers the specified window as one that can be the target of an OLE drag-and-drop operation and specifies the [IDropTarget](https://learn.microsoft.com/windows/win32/api/oleidl/nn-oleidl-idroptarget) instance to use for drop operations.

## Parameters

### `hwnd` [in]

Handle to a window that can be a target for an OLE drag-and-drop operation.

### `pDropTarget` [in]

Pointer to the [IDropTarget](https://learn.microsoft.com/windows/win32/api/oleidl/nn-oleidl-idroptarget) interface on the object that is to be the target of a drag-and-drop operation in a specified window. This interface is used to communicate OLE drag-and-drop information for that window.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **DRAGDROP_E_INVALIDHWND** | Invalid handle returned in the hwnd parameter. |
| **DRAGDROP_E_ALREADYREGISTERED** | The specified window has already been registered as a drop target. |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |

**Note** If you use [CoInitialize](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-coinitialize) or [CoInitializeEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex) instead of [OleInitialize](https://learn.microsoft.com/windows/win32/api/ole2/nf-ole2-oleinitialize) to initialize COM, **RegisterDragDrop** will always return an E_OUTOFMEMORY error.

## Remarks

If your application can accept dropped objects during OLE drag-and-drop operations, you must call the **RegisterDragDrop** function. Do this whenever one of your application windows is available as a potential drop target; that is, when the window appears unobscured on the screen.

The application thread that calls the **RegisterDragDrop** function must be pumping messages, presumably by calling the [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) function with a **NULL** *hWnd* parameter, because OLE creates windows on the thread that need messages processed. If this requirement isn't met, then any application that drags an object over the window that is registered as a drop target will hang until the target application closes.

The **RegisterDragDrop** function only registers one window at a time, so you must call it for each application window capable of accepting dropped objects.

As the mouse passes over unobscured portions of the target window during an OLE drag-and-drop operation, the [DoDragDrop](https://learn.microsoft.com/windows/win32/api/ole2/nf-ole2-dodragdrop) function calls the specified [IDropTarget::DragOver](https://learn.microsoft.com/windows/win32/api/oleidl/nf-oleidl-idroptarget-dragover) method for the current window. When a drop operation actually occurs in a given window, the **DoDragDrop** function calls [IDropTarget::Drop](https://learn.microsoft.com/windows/win32/api/oleidl/nf-oleidl-idroptarget-drop).

The **RegisterDragDrop** function also calls the [IUnknown::AddRef](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) method on the [IDropTarget](https://learn.microsoft.com/windows/win32/api/oleidl/nn-oleidl-idroptarget) pointer.

## See also

[RevokeDragDrop](https://learn.microsoft.com/windows/win32/api/ole2/nf-ole2-revokedragdrop)