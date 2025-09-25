# ITextHost::TxViewChange

## Description

Indicates to the text host that the update region has changed.

## Parameters

### `fUpdate` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Update flag. If **TRUE**, the text host calls [UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow); otherwise it does nothing. See the Remarks section.

## Remarks

The text services object must call **TxViewChange** every time its visual representation has changed, even if the control is inactive. If the control is active, then text services must also make sure the control's window is updated. It can do this in a number of ways:

* Call [ITextHost::TxGetDC](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetdc) to get a device context for the control's window and then repaint or update the window. Afterward, call [ITextHost::TxReleaseDC](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txreleasedc).
* Call [ITextHost::TxInvalidateRect](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txinvalidaterect) to invalidate the control's window.
* Call [ITextHost::TxScrollWindowEx](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txscrollwindowex) to scroll the control's window.

After the text services object has updated the active view, it can call **TxViewChange** and set *fUpdate* to **TRUE** along with the call. By passing **TRUE**, the text host calls [UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow) to make sure any unpainted areas of the active control are repainted.

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Reference**

[TxGetDC](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetdc)

[TxInvalidateRect](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txinvalidaterect)

[TxReleaseDC](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txreleasedc)

[TxScrollWindowEx](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txscrollwindowex)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)