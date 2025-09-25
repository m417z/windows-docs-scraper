# TabCtrl_SetItemExtra macro

## Syntax

```cpp
BOOL TabCtrl_SetItemExtra(
   HWND hwndTC,
   int  cb
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets the number of bytes per tab reserved for application-defined data in a tab control. You can use this macro or send the [TCM_SETITEMEXTRA](https://learn.microsoft.com/windows/desktop/Controls/tcm-setitemextra) message explicitly.

## Parameters

### `hwndTC`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `cb`

Type: **int**

Number of extra bytes.

## Remarks

By default, the number of extra bytes is four. An application that changes the number of extra bytes cannot use the [TCITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tcitema) structure to retrieve and set the application-defined data for a tab. Instead, you must define a new structure that consists of the [TCITEMHEADER](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tcitemheadera) structure followed by application-defined members.

An application should only change the number of extra bytes when a tab control does not contain any tabs.