# ListView_SetCheckState macro

## Syntax

```cpp
void ListView_SetCheckState(
   HWND hwndLV,
   UINT i,
   BOOL fCheck
);
```

## Description

Selects or deselects an item in a list-view control. You can use this macro or send the [LVM_SETITEMSTATE](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitemstate) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `i`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the item for which to set the check state.

### `fCheck`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that is set to **TRUE** to select the item, or **FALSE** to deselect it.

## Remarks

This macro should only be used for list-view controls with the [LVS_EX_CHECKBOXES](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles) style.

## See also

[ListView_SetItemState](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setitemstate)