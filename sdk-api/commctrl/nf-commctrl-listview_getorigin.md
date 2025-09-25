# ListView_GetOrigin macro

## Syntax

```cpp
BOOL ListView_GetOrigin(
   HWND    hwndLV,
   LPPOINT ppt
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** if the current view is list or report view.

## Description

Gets the current view origin for a list-view control. You can use this macro or send the [LVM_GETORIGIN](https://learn.microsoft.com/windows/desktop/Controls/lvm-getorigin) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `ppt`

Type: **LPPOINT**

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the view origin.