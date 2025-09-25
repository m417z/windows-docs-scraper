# ListView_GetInsertMark macro

## Syntax

```cpp
BOOL ListView_GetInsertMark(
   HWND          hwnd,
   PLVINSERTMARK lvim
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise. Returns **FALSE** if the size in the **cbSize** member of the **LVINSERTMARK** structure does not equal the actual size of the structure.

## Description

Gets the position of the insertion point. You can use this macro or send the [LVM_GETINSERTMARK](https://learn.microsoft.com/windows/desktop/Controls/lvm-getinsertmark) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `lvim`

Type: **PLVINSERTMARK**

[LVINSERTMARK](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvinsertmark)

## Remarks

To use **ListView_GetInsertMark**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).