# NMLVKEYDOWN structure

## Description

Contains information used in processing the [LVN_KEYDOWN](https://learn.microsoft.com/windows/desktop/Controls/lvn-keydown) notification code. This structure is the same as the
**NMLVKEYDOWN** structure but has been renamed to fit standard naming conventions.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `wVKey`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Virtual key code](https://learn.microsoft.com/windows/desktop/inputdev/virtual-key-codes).

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This member must always be zero.