# NMLISTVIEW structure

## Description

Contains information about a list-view notification message. This structure is the same as the **NM_LISTVIEW** structure but has been renamed to fit standard naming conventions.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification message.

### `iItem`

Type: **int**

Identifies the list-view item, or -1 if not used.

### `iSubItem`

Type: **int**

Identifies the subitem, or zero if none.

### `uNewState`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New item state. This member is zero for notification messages that do not use it. For a list of possible values, see [List-View Item States](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states).

### `uOldState`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Old item state. This member is zero for notification messages that do not use it. For a list of possible values, see [List-View Item States](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states).

### `uChanged`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set of flags that indicate the item attributes that have changed. This member is zero for notifications that do not use it. Otherwise, it can have the same values as the
**mask** member of the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure.

### `ptAction`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that indicates the location at which the event occurred. This member is undefined for notification messages that do not use it.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined value of the item. This member is undefined for notification messages that do not use it.