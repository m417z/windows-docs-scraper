# MonthCal_GetCalendarCount macro

## Syntax

```cpp
DWORD MonthCal_GetCalendarCount(
   HWND hmc
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Number of calendars currently displayed in the calendar control. The maximum number of allowed calendars is 12.

## Description

Gets the number of calendars currently displayed in the calendar control. You can use this macro or send the [MCM_GETCALENDARCOUNT](https://learn.microsoft.com/windows/desktop/Controls/mcm-getcalendarcount) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.