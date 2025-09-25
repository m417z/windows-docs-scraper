# MonthCal_SetCALID macro

## Syntax

```cpp
LRESULT MonthCal_SetCALID(
   HWND hmc,
   UINT calid
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Unused.

## Description

Sets the calendar ID for the given calendar control. You can use this macro or send the [MCM_SETCALID](https://learn.microsoft.com/windows/desktop/Controls/mcm-setcalid) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `calid`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Calendar ID. One of the [Calendar Identifiers](https://learn.microsoft.com/windows/desktop/Intl/calendar-identifiers) constants.