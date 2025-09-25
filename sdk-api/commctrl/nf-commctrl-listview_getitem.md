# ListView_GetItem macro

## Syntax

```cpp
BOOL ListView_GetItem(
   HWND     hwnd,
   LPLVITEM pitem
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets some or all of a list-view item's attributes. You can use this macro or send the [LVM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `pitem`

Type: **LPLVITEM**

A pointer to an [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure that specifies the information to retrieve and receives information about the list-view item.

## Remarks

When the [LVM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitem) message is sent, the
**iItem** and **iSubItem** members identify the item or subitem to retrieve information about and the **mask** member specifies which attributes to retrieve. For a list of possible values, see the description of the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure.

If the LVIF_TEXT flag is set in the **mask** member of the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure, the **pszText** member must point to a valid buffer and the **cchTextMax** member must be set to the number of characters in that buffer. Applications should not assume that the text will necessarily be placed in the specified buffer. The control may instead change the **pszText** member of the structure to point to the new text rather than place it in the buffer.

If the **mask** member specifies the LVIF_STATE value, the **stateMask** member must specify the item state bits to retrieve. On output, the **state** member contains the values of the specified state bits.