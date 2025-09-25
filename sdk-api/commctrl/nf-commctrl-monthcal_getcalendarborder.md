# MonthCal_GetCalendarBorder macro

## Syntax

```cpp
DWORD MonthCal_GetCalendarBorder(
   HWND hmc
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Current border size, in pixels.

## Description

Gets the border size, in pixels, of a month calendar control. You can use this macro or send the [MCM_GETCALENDARBORDER](https://learn.microsoft.com/windows/desktop/Controls/mcm-getcalendarborder) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.