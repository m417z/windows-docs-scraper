# MonthCal_GetFirstDayOfWeek macro

## Syntax

```cpp
DWORD MonthCal_GetFirstDayOfWeek(
   HWND hmc
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **DWORD** value that contains two values. The high word is a **BOOL** value that is nonzero if the first day of the week is set to something other than LOCALE_IFIRSTDAYOFWEEK, or zero otherwise. The low word is an INT value that represents the first day of the week, where 0 is Monday, 1 is Tuesday, and so on.

## Description

Retrieves the first day of the week for a month calendar control. You can use this macro or send the [MCM_GETFIRSTDAYOFWEEK](https://learn.microsoft.com/windows/desktop/Controls/mcm-getfirstdayofweek) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.