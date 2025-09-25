# SetClipboardViewer function

## Description

Adds the specified window to the chain of clipboard viewers. Clipboard viewer windows receive a [WM_DRAWCLIPBOARD](https://learn.microsoft.com/windows/desktop/dataxchg/wm-drawclipboard) message whenever the content of the clipboard changes. This function is used for backward compatibility with earlier versions of Windows.

## Parameters

### `hWndNewViewer` [in]

Type: **HWND**

A handle to the window to be added to the clipboard chain.

## Return value

Type: **HWND**

If the function succeeds, the return value identifies the next window in the clipboard viewer chain. If an error occurs or there are no other windows in the clipboard viewer chain, the return value is NULL. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The windows that are part of the clipboard viewer chain, called clipboard viewer windows, must process the clipboard messages [WM_CHANGECBCHAIN](https://learn.microsoft.com/windows/desktop/dataxchg/wm-changecbchain) and [WM_DRAWCLIPBOARD](https://learn.microsoft.com/windows/desktop/dataxchg/wm-drawclipboard). Each clipboard viewer window calls the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function to pass these messages to the next window in the clipboard viewer chain.

A clipboard viewer window must eventually remove itself from the clipboard viewer chain by calling the [ChangeClipboardChain](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changeclipboardchain) function — for example, in response to the [WM_DESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-destroy) message.

The **SetClipboardViewer** function exists to provide backward compatibility with earlier versions of Windows. The clipboard viewer chain can be broken by an application that fails to handle the clipboard chain messages properly. New applications should use more robust techniques such as the clipboard sequence number or the registration of a clipboard format listener. For further details on these alternatives techniques, see [Monitoring Clipboard Contents](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

#### Examples

For an example, see [Adding a Window to the Clipboard Viewer Chain](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

[ChangeClipboardChain](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changeclipboardchain)

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[GetClipboardViewer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipboardviewer)

**Reference**

[SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage)