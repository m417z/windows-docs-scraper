# IOleInPlaceFrame::SetStatusText

## Description

Sets and displays status text about the in-place object in the container's frame window status line.

## Parameters

### `pszStatusText` [in]

The message to be displayed.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_TRUNCATED** | Some text was displayed but the message was too long and was truncated. |
| **E_FAIL** | The operation failed. |
| **E_INVALIDARG** | The specified pointer is invalid. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

### Notes to Callers

You should call **IOleInPlaceFrame::SetStatusText** when you need to ask the container to display object text in its frame's status line, if it has one. Because the container's frame window owns the status line, calling **IOleInPlaceFrame::SetStatusText** is the only way an object can display status information in the container's frame window. If the container refuses the object's request, the object application can, however, negotiate for border space to display its own status window.

When switching between menus owned by the container and the in-place active object, the status bar text is not reflected properly if the object does not call the container's **IOleInPlaceFrame::SetStatusText** method. For example, if, during an in-place session, the user were to select the **File** menu, the status bar would reflect the action that would occur if the user selected this menu. If the user then selects the **Edit** menu (which is owned by the in-place object), the status bar text would not change unless the **IOleInPlaceFrame::SetStatusText** happened to be called. This is because there is no way for the container to recognize that one of the object's menus has been made active because all the messages that the container would trap are now going to the object.

### Notes to Implementers

To avoid potential problems, all objects being activated in place should process the [WM_MENUSELECT](https://learn.microsoft.com/windows/desktop/menurc/wm-menuselect) message and call **IOleInPlaceFrame::SetStatusText**, even if the object does not usually provide status information (in which case the object can just pass a **NULL** string for the requested status text).

**Note** While executing **IOleInPlaceFrame::SetStatusText**, do not make calls to the [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) or [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) functions, or a dialog box. Doing so may cause the system to deadlock. There are further restrictions on which OLE interface methods and functions can be called from within [IOleInPlaceUIWindow::GetBorder](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceuiwindow-getborder).

## See also

[GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb)

[IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)