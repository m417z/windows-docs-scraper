# ChangeClipboardChain function

## Description

Removes a specified window from the chain of clipboard viewers.

## Parameters

### `hWndRemove` [in]

Type: **HWND**

A handle to the window to be removed from the chain. The handle must have been passed to the [SetClipboardViewer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboardviewer) function.

### `hWndNewNext` [in]

Type: **HWND**

A handle to the window that follows the
*hWndRemove* window in the clipboard viewer chain. (This is the handle returned by [SetClipboardViewer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboardviewer), unless the sequence was changed in response to a [WM_CHANGECBCHAIN](https://learn.microsoft.com/windows/desktop/dataxchg/wm-changecbchain) message.)

## Return value

Type: **BOOL**

The return value indicates the result of passing the [WM_CHANGECBCHAIN](https://learn.microsoft.com/windows/desktop/dataxchg/wm-changecbchain) message to the windows in the clipboard viewer chain. Because a window in the chain typically returns **FALSE** when it processes **WM_CHANGECBCHAIN**, the return value from **ChangeClipboardChain** is typically **FALSE**. If there is only one window in the chain, the return value is typically **TRUE**.

## Remarks

The window identified by
*hWndNewNext* replaces the
*hWndRemove* window in the chain. The [SetClipboardViewer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboardviewer) function sends a [WM_CHANGECBCHAIN](https://learn.microsoft.com/windows/desktop/dataxchg/wm-changecbchain) message to the first window in the clipboard viewer chain.

For an example, see [Removing a Window from the Clipboard Viewer Chain](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

[ChangeClipboardChain](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changeclipboardchain)

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

**Reference**

[SetClipboardViewer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboardviewer)

[WM_CHANGECBCHAIN](https://learn.microsoft.com/windows/desktop/dataxchg/wm-changecbchain)