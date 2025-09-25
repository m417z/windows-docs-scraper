# NMITEMACTIVATE structure

## Description

Contains information about an [LVN_ITEMACTIVATE](https://learn.microsoft.com/windows/desktop/Controls/lvn-itemactivate) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification code.

### `iItem`

Type: **int**

Index of the list-view item. If the item index is not used for the notification, this member will contain -1.

### `iSubItem`

Type: **int**

One-based index of the subitem. If the subitem index is not used for the notification or the notification does not apply to a subitem, this member will contain zero.

### `uNewState`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New item state. This member is zero for notification codes that do not use it.

### `uOldState`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Old item state. This member is zero for notification codes that do not use it.

### `uChanged`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set of flags that indicate the item attributes that have changed. This member is zero for notifications that do not use it. Otherwise, it can have the same values as the
**mask** member of the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure.

### `ptAction`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that indicates the location at which the event occurred, in client coordinates. This member is undefined for notification codes that do not use it.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined value of the item. This member is undefined for notification codes that do not use it.

### `uKeyFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Modifier keys that were pressed at the time of the activation. This member contains zero or a combination of the following flags:

| Value | Meaning |
| --- | --- |
| **LVKF_ALT** | The key is pressed. |
| **LVKF_CONTROL** | The key is pressed. |
| **LVKF_SHIFT** | The key is pressed. |