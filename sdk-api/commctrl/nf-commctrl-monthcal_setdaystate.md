# MonthCal_SetDayState macro

## Syntax

```cpp
BOOL MonthCal_SetDayState(
   HWND            hmc,
   INT             cbds,
   LPMONTHDAYSTATE rgds
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Sets the day states for all months that are currently visible within a month calendar control. You can use this macro or send the [MCM_SETDAYSTATE](https://learn.microsoft.com/windows/desktop/Controls/mcm-setdaystate) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `cbds`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value of type **int** indicating how many elements are in the array that *rgds* points to.

### `rgds`

Type: **LPMONTHDAYSTATE**

Pointer to an array of [MONTHDAYSTATE](https://learn.microsoft.com/windows/desktop/Controls/monthdaystate) values that define how the month calendar control will draw each day in its display.

## Remarks

An application can explicitly set day state information by using this macro, but the state will not persist when a different part of the calendar is scrolled into view. Day state information is usually set in response to the [MCN_GETDAYSTATE](https://learn.microsoft.com/windows/desktop/Controls/mcn-getdaystate) notification code, which is sent whenever the control needs to be refreshed.

The array at *rgds* must contain as many elements as the value returned by the following macro:

`MonthCal_GetMonthRange(hmc, GMR_DAYSTATE, NULL);`

The preceding macro returns the total number of months that are in complete or partial view within the month calendar's display.

Keep in mind that the array at *rgds* must contain [MONTHDAYSTATE](https://learn.microsoft.com/windows/desktop/Controls/monthdaystate) values that correspond with all months currently in the control's display, in chronological order. This includes the two months that may be partially displayed before the first month and after the last month.

## See also

[Using Month Calendar Controls](https://learn.microsoft.com/windows/desktop/Controls/using-month-calendar-controls)