# ITextHost::TxGetScrollBars

## Description

Requests information about the scroll bars supported by the text host.

## Parameters

### `pdwScrollBar`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The scroll bar. This parameter can be a combination of the following window styles related to scroll bars.

| Value | Meaning |
| --- | --- |
| **WS_VSCROLL** | Supports a vertical scroll bar. |
| **WS_HSCROLL** | Supports a horizontal scroll bar. |
| **ES_AUTOVSCROLL** | Automatically scrolls text up one page when the user presses ENTER on the last line. |
| **ES_AUTOHSCROLL** | Automatically scrolls text to the right by 10 characters when the user types a character at the end of the line. When the user presses ENTER, the control scrolls all text back to position zero. |
| **ES_DISABLENOSCROLL** | Disables scroll bars instead of hiding them when they are not needed. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value is **S_OK**.

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)