# LVITEMINDEX structure

## Description

Contains index information about a list-view item.

## Members

### `iItem`

Type: **int**

The index of the item.

### `iGroup`

Type: **int**

The index of the group the item belongs to.

## Remarks

This structure is used with the [ListView_GetItemIndexRect](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_getitemindexrect), [ListView_GetNextItemIndex](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_getnextitemindex), and [ListView_SetItemIndexState](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setitemindexstate) macros. It is also used with the [LVM_GETITEMINDEXRECT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitemindexrect), [LVM_GETNEXTITEMINDEX](https://learn.microsoft.com/windows/desktop/controls/lvm-getnextitemindex), and [LVM_SETITEMINDEXSTATE](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitemindexstate) messages.