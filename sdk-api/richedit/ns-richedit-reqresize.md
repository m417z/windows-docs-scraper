# REQRESIZE structure

## Description

Contains the requested size of a rich edit control. A rich edit control sends this structure to its parent window as part of an [EN_REQUESTRESIZE](https://learn.microsoft.com/windows/win32/controls/en-requestresize) notification code.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)**

Notification header.

### `rc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

Requested new size.

## See also

[EN_REQUESTRESIZE](https://learn.microsoft.com/windows/win32/controls/en-requestresize)