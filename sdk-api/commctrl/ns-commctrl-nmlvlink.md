# NMLVLINK structure

## Description

Contains information about an [LVN_LINKCLICK](https://learn.microsoft.com/windows/desktop/Controls/lvn-linkclick) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains basic information about the notification code.

### `link`

Type: **[LITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-litem)**

[LITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-litem) structure that contains information about the link that was clicked.

### `iItem`

Type: **int**

Index of the item that contains the link.

### `iSubItem`

Type: **int**

Subitem, if any. This member may be **NULL**. For a link in a group header, this is the group identifier, as set in [LVGROUP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroup).