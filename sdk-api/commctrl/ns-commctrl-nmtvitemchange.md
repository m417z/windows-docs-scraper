# NMTVITEMCHANGE structure

## Description

Contains information on a tree-view item change. This structure is sent with the [TVN_ITEMCHANGED](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemchanged) and [TVN_ITEMCHANGING](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemchanging) notifications.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification.

### `uChanged`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the attribute. The only supported attribute is state. **uChanged** must have the following value:

| Value | Meaning |
| --- | --- |
| TVIF_STATE | The change is the state attribute. |

### `hItem`

Type: **HTREEITEM**

Handle to the changed tree-view item.

### `uStateNew`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag that specifies the new item state.

### `uStateOld`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag that specifies the item's previous state.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved for application specific data. For example, a value to associate with the item.