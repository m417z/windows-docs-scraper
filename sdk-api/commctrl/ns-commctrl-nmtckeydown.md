# NMTCKEYDOWN structure

## Description

Contains information about a key press in a tab control. It is used with the [TCN_KEYDOWN](https://learn.microsoft.com/windows/desktop/Controls/tcn-keydown) notification code. This structure supersedes the
**TC_KEYDOWN** structure.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification.

### `wVKey`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Virtual key code.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value that is identical to the
*lParam* parameter of the [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown) message.