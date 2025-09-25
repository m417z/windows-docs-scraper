# NMMOUSE structure

## Description

Contains information used with mouse notification messages.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about this notification.

### `dwItemSpec`

Type: **[DWORD_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A control-specific item identifier.

### `dwItemData`

Type: **[DWORD_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A control-specific item data.

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the client coordinates of the mouse when the click occurred.

### `dwHitInfo`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Carries information about where on the item or control the cursor is pointing.