# MonthCal_SetFirstDayOfWeek macro

## Syntax

```cpp
DWORD MonthCal_SetFirstDayOfWeek(
   HWND hmc,
   INT  iDay
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **DWORD** value that contains two values. The high word is a **BOOL** value that is nonzero if the previous first day of the week did not equal LOCALE_IFIRSTDAYOFWEEK, or zero otherwise. The low word is an INT value that represents the previous first day of the week.

## Description

Sets the first day of the week for a month calendar control. You can use this macro or send the [MCM_SETFIRSTDAYOFWEEK](https://learn.microsoft.com/windows/desktop/Controls/mcm-setfirstdayofweek) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `iDay`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value of type **int** that specifies which day is to be set as the first day of the week, where 0 is Monday, 1 is Tuesday, and so on.

## Remarks

If the first day of the week is set to anything other than the default (LOCALE_IFIRSTDAYOFWEEK), the control will not automatically update first-day-of-the-week changes based on locale changes.