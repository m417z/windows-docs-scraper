# ListView_GetBkImage macro

## Syntax

```cpp
BOOL ListView_GetBkImage(
   HWND        hwnd,
   LPLVBKIMAGE plvbki
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Gets the background image in a list-view control. You can use this macro or send the [LVM_GETBKIMAGE](https://learn.microsoft.com/windows/desktop/Controls/lvm-getbkimage) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `plvbki`

Type: **LPLVBKIMAGE**

A pointer to a [LVBKIMAGE](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvbkimagea) structure that will receive the background image information.

## See also

[ListView_SetBkImage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setbkimage)