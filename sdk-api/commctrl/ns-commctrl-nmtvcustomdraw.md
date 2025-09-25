# NMTVCUSTOMDRAW structure

## Description

Contains information specific to an [NM_CUSTOMDRAW (tree view)](https://learn.microsoft.com/windows/desktop/Controls/nm-customdraw-tree-view) notification code sent by a tree-view control.

## Members

### `nmcd`

Type: **[NMCUSTOMDRAW](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-nmcustomdraw)**

[NMCUSTOMDRAW](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-nmcustomdraw) structure that contains general custom draw information.

### `clrText`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value representing the color that will be used to display text foreground in the tree-view control.

### `clrTextBk`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value representing the color that will be used to display text background in the tree-view control.

### `iLevel`

Type: **int**

[Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Zero-based level of the item being drawn. The root item is at level zero, a child of the root item is at level one, and so on.