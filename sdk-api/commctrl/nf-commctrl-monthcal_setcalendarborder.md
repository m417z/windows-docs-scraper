# MonthCal_SetCalendarBorder macro

## Syntax

```cpp
LRESULT MonthCal_SetCalendarBorder(
   HWND hmc,
   BOOL fset,
   int  xyborder
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Unused.

## Description

Sets the border size, in pixels, of a month calendar control. You can use this macro or send the [MCM_SETCALENDARBORDER](https://learn.microsoft.com/windows/desktop/Controls/mcm-setcalendarborder) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `fset`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **TRUE**, then the border size is set to the number of pixels that *xyborder* specifies. If **FALSE**, then the border size is reset to the default value specified by the theme, or zero if themes are not being used.

### `xyborder`

Type: **int**

Number of pixels of the border size.