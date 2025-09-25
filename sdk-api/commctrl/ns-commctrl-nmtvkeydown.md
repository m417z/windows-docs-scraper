# NMTVKEYDOWN structure

## Description

Contains information about a keyboard event in a tree-view control. This structure is used with the [TVN_KEYDOWN](https://learn.microsoft.com/windows/desktop/Controls/tvn-keydown) notification code. The structure is identical to the
**TV_KEYDOWN** structure, but it has been renamed to follow current naming conventions.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification.

### `wVKey`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Virtual key code.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Always zero.

## See also

[WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify)