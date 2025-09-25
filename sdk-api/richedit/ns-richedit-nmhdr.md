# NMHDR structure

## Description

Contains information about a notification message.

## Members

### `hwndFrom`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A window handle to the control sending the message.

### `idFrom`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An identifier of the control sending the message.

### `code`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A notification code. This member can be one of the common notification codes (see Notifications under [General Control Reference](https://learn.microsoft.com/windows/win32/controls/common-control-reference)), or it can be a control-specific notification code.