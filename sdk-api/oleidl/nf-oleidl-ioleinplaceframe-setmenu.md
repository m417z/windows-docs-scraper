# IOleInPlaceFrame::SetMenu

## Description

Adds a composite menu to the window frame containing the object being activated in place.

## Parameters

### `hmenuShared` [in]

A handle to the composite menu constructed by calls to [IOleInPlaceFrame::InsertMenus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-insertmenus) and the [InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua) function.

### `holemenu` [in]

A handle to the menu descriptor returned by the [OleCreateMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatemenudescriptor) function.

### `hwndActiveObject` [in]

A handle to a window owned by the object and to which menu messages, commands, and accelerators are to be sent.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The specified handle is invalid. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

### Notes to Callers

The object calls **IOleInPlaceFrame::SetMenu** to ask the container to install the composite menu structure set up by calls to [IOleInPlaceFrame::InsertMenus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-insertmenus).

### Notes to Implementers

An SDI container's implementation of this method should call the [SetMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenu) function. An MDI container should send a [WM_MDISETMENU](https://learn.microsoft.com/windows/desktop/winmsg/wm-mdisetmenu) message, using *hmenuShared* as the menu to install. The container should call [OleSetMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetmenudescriptor) to install the OLE dispatching code.

When deactivating, the container must call **IOleInPlaceFrame::SetMenu**, specifying **NULL** to remove the shared menu. This is done to help minimize window repaints. The container should also call [OleSetMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetmenudescriptor), specifying **NULL** to unhook the dispatching code. Finally, the object application calls [OleDestroyMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oledestroymenudescriptor) to free the data structure.

**Note** While executing **IOleInPlaceFrame::SetMenu**, do not make calls to the [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) or [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) functions, or a dialog box. Doing so may cause the system to deadlock. There are further restrictions on which OLE interface methods and functions can be called from within **IOleInPlaceFrame::SetMenu**.

## See also

[IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe)

[IOleInPlaceFrame::InsertMenus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-insertmenus)

[InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua)

[OleDestroyMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oledestroymenudescriptor)

[OleSetMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetmenudescriptor)