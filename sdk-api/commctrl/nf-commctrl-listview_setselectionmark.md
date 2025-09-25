# ListView_SetSelectionMark macro

## Syntax

```cpp
INT ListView_SetSelectionMark(
   HWND hwnd,
   INT  i
);
```

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the previous selection mark, or -1 if there is no previous selection mark.

## Description

Sets the selection mark in a list-view control. You can use this macro or send the [LVM_SETSELECTIONMARK](https://learn.microsoft.com/windows/desktop/Controls/lvm-setselectionmark) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `i`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

the zero-based index of the list-view item to be selected.

## Remarks

The selection mark is the item index from which a multiple selection starts. This macro does not affect the selection state of the item.

## See also

[ListView_GetSelectionMark](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_getselectionmark)