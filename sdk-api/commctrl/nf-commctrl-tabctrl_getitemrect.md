# TabCtrl_GetItemRect macro

## Syntax

```cpp
BOOL TabCtrl_GetItemRect(
   HWND hwnd,
   int  i,
   RECT *prc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Retrieves the bounding rectangle for a tab in a tab control. You can use this macro or send the [TCM_GETITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/tcm-getitemrect) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `i`

Type: **int**

Index of the tab.

### `prc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a structure that receives the bounding rectangle of the tab, in viewport coordinates.