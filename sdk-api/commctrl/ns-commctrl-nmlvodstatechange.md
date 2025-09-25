# NMLVODSTATECHANGE structure

## Description

Structure that contains information for use in processing the [LVN_ODSTATECHANGED](https://learn.microsoft.com/windows/desktop/Controls/lvn-odstatechanged) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `iFrom`

Type: **int**

Zero-based index of the first item in the range of items.

### `iTo`

Type: **int**

Zero-based index of the last item in the range of items.

### `uNewState`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value indicating the new state for the item or items. This member can be any valid combination of the [list-view item states](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states).

### `uOldState`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value indicating the old state for the item or items. This member can be any valid combination of the [list-view item states](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states).