# CLIPBOARDFORMAT structure

## Description

Specifies the clipboard format. This structure included with the [EN_CLIPFORMAT](https://learn.microsoft.com/windows/desktop/Controls/en-clipformat) notification.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)**

Structure that contains information about this notification message.

### `cf`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A clipboard format registered by a call to the [RegisterClipboardFormat](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerclipboardformata) function.

## See also

[EN_CLIPFORMAT](https://learn.microsoft.com/windows/desktop/Controls/en-clipformat)