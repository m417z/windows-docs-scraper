# ITextServices::OnTxInPlaceDeactivate

## Description

Notifies the text services object that this control is no longer in-place active.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value is always **S_OK**.

## Remarks

In-place activation refers to an embedded object *running in-place* (for example, for regular controls and embeddings, it would have a window to draw in). In contrast, UI active means that an object currently has the *editing focus*. Specifically, things like menus and toolbars on the container may also contain elements from the UI-active control/embedding. There can only be one UI-active control at any given time, while many can be in-place active at once.

Note, UI activation is different from getting the focus. To let the text services object know that the control is getting or losing focus, the host will send [WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus) and [WM_KILLFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-killfocus) messages. Also, note that a windowless host will pass **NULL** as the *wParam* (window that lost the focus) for these messages.

When making the transition from the UI-active state to a nonactive state, the host should call [ITextServices::OnTxUIDeactivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxuideactivate) first and then **ITextServices::OnTxInPlaceDeactivate**.

## See also

**Conceptual**

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

[OnTxUIDeactivate](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxuideactivate)

**Other Resources**

**Reference**

[WM_KILLFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-killfocus)

[WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)