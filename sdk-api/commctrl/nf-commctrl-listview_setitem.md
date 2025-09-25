# ListView_SetItem macro

## Syntax

```cpp
BOOL ListView_SetItem(
         HWND     hwnd,
   const LPLVITEM pitem
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets some or all of a list-view item's attributes. You can also use **ListView_SetItem** to set the text of a subitem. You can use this macro or send the [LVM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `pitem`

Type: **const LPLVITEM**

A pointer to an [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure that contains the new item attributes. The **iItem** and
**iSubItem** members identify the item or subitem, and the
**mask** member specifies which attributes to set. If the **mask** member specifies the LVIF_TEXT value, the **pszText** member is the address of a null-terminated string and the **cchTextMax** member is ignored. If the **mask** member specifies the LVIF_STATE value, the **stateMask** member specifies which item states to change, and the **state** member contains the values for those states.

## Remarks

To set the attributes of a list-view item, set the
**iItem** member of the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure to the index of the item, and set the
**iSubItem** member to zero. For an item, you can use the
**state**, **pszText**,
**iImage**, and **lParam** members of the **LVITEM** structure to modify these item parameters.

To set the text of a subitem, set the **iItem** and **iSubItem** members to indicate the specific subitem, and use the **pszText** member to specify the text. Alternatively, you can use the [ListView_SetItemText](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setitemtext) macro to set the text of a subitem. You cannot set the **state** or **lParam** members for subitems because subitems do not have these attributes. In version 4.70 and later, you can set the **iImage** member for subitems. The subitem image will be displayed if the list-view control has the [LVS_EX_SUBITEMIMAGES](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles) extended style. Previous versions will ignore the subitem image.