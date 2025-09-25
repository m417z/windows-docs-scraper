# Edit_GetEndOfLine macro

## Syntax

```cpp
EC_ENDOFLINE Edit_GetEndOfLine(
    HWND hwndCtl
);
```

## Return value

Type: **EC_ENDOFLINE**

Returns an [EC_ENDOFLINE](https://learn.microsoft.com/windows/win32/api/commctrl/ne-commctrl-ec_endofline) value that represents the end of line character currently in use for a given edit control.

It can be one of the following **EC_ENDOFLINE** values.

| Value | Meaning |
|-|-|
| **EC_ENDOFLINE_CRLF** | The end-of-line character used for new linebreaks is carriage return followed by linefeed (CRLF). |
| **EC_ENDOFLINE_CR** | The end-of-line character used for new linebreaks is carriage return (CR). |
| **EC_ENDOFLINE_LF** | The end-of-line character used for new linebreaks is linefeed (LF). |

## Description

Gets the end of line character used for the content of the edit control. You can use this macro or send the [EM_GETENDOFLINE](https://learn.microsoft.com/windows/desktop/controls/em-getendofline) message explicitly.

## Parameters

### `hwndCtl`

A handle to the edit control.