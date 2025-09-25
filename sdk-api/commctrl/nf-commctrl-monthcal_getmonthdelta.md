# MonthCal_GetMonthDelta macro

## Syntax

```cpp
INT MonthCal_GetMonthDelta(
   HWND hmc
);
```

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the month delta was previously set using the **MonthCal_SetMonthDelta** macro, returns an INT value that represents the month calendar's current scroll rate. If the month delta was not previously set using the **MonthCal_SetMonthDelta** macro, or the month delta was reset to the default, returns an INT value that represents the current number of months visible.

## Description

Retrieves the scroll rate for a month calendar control. The scroll rate is the number of months that the control moves its display when the user clicks a scroll button. You can use this macro or send the [MCM_GETMONTHDELTA](https://learn.microsoft.com/windows/desktop/Controls/mcm-getmonthdelta) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.