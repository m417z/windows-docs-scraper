# TabCtrl_HitTest macro

## Syntax

```cpp
int TabCtrl_HitTest(
   HWND            hwndTC,
   LPTCHITTESTINFO pinfo
);
```

## Return value

Type: **int**

Returns the index of the tab, or -1 if no tab is at the specified position.

## Description

Determines which tab, if any, is at a specified screen position. You can use this macro or send the [TCM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/tcm-hittest) message explicitly.

## Parameters

### `hwndTC`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `pinfo`

Type: **LPTCHITTESTINFO**

Pointer to a [TCHITTESTINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tchittestinfo) structure that specifies the screen position to test.