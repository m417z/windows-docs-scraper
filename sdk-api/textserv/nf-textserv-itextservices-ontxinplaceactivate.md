# ITextServices::OnTxInPlaceActivate

## Description

Notifies the text services object that this control is in-place active.

## Parameters

### `prcClient` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

The control's client rectangle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the object is successfully activated, the return value is **S_OK**.

If the object could not be activated due to error, the return value is E_FAIL. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

In-place active means that an embedded object is *running in-place* (for example, for regular controls and embeddings, it would have a window to draw in). In contrast, UI active means that an object currently has the *editing focus*. For example, things like menus and toolbars on the container may also contain elements from the UI-active control/embedding. There is only one UI-active control at any given time, while there can be many in-place active controls.

Note, UI activation is different from getting the focus. To signal the text services object that the control is getting or losing focus, the host sends [WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus) and [WM_KILLFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-killfocus) messages. Also, note that a windowless host will pass **NULL** as the *wParam* (window that lost the focus) for these messages.

When making the transition directly from a nonactive state to the UI-active state, the host should call **ITextServices::OnTxInPlaceActivate** first and then [ITextServices::OnTxUIActivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxuiactivate).

**ITextServices::OnTxInPlaceActivate** takes as a parameter the client rectangle of the view being activated. This rectangle is given in client coordinates of the containing window. It is the same as would be obtained by calling [TxGetClientRect](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetclientrect) on the host.

## See also

**Conceptual**

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

[OnTxUIActivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxuiactivate)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**

[TxGetClientRect](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetclientrect)

[WM_KILLFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-killfocus)

[WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)