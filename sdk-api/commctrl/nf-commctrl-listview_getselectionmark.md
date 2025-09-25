# ListView_GetSelectionMark macro

## Syntax

```cpp
INT ListView_GetSelectionMark(
   HWND hwnd
);
```

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the zero-based selection mark, or -1 if there is no selection mark.

## Description

Gets the selection mark from a list-view control. You can use this macro or explicitly send the [LVM_GETSELECTIONMARK](https://learn.microsoft.com/windows/desktop/Controls/lvm-getselectionmark) message.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

## Remarks

The selection mark is the item index from which a multiple selection starts.

## See also

[ListView_SetSelectionMark](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setselectionmark)