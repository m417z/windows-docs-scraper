# MonthCal_GetCalendarGridInfo macro

## Syntax

```cpp
BOOL MonthCal_GetCalendarGridInfo(
   HWND       hmc,
   MCGRIDINFO *pmcGridInfo
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if successful, otherwise **FALSE**.

## Description

Gets information about a calendar grid.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `pmcGridInfo`

Type: **[MCGRIDINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-mcgridinfo)***

Pointer to an [MCGRIDINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-mcgridinfo) structure that contains information about the calendar grid.