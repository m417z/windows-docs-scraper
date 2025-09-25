# ListView_SetInsertMark macro

## Syntax

```cpp
BOOL ListView_SetInsertMark(
   HWND          hwnd,
   PLVINSERTMARK lvim
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise. Returns **FALSE** if the size of the **LVINSERTMARK** structure's **cbSize** member does not equal the actual size of the structure, or when an insertion point does not apply in the current view.

## Description

Sets the insertion point to the defined position. You can use this macro or send the [LVM_SETINSERTMARK](https://learn.microsoft.com/windows/desktop/Controls/lvm-setinsertmark) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `lvim`

Type: **PLVINSERTMARK**

[LVINSERTMARK](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvinsertmark)

## Remarks

To use **ListView_SetInsertMark**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).