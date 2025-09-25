# MonthCal_SetToday macro

## Syntax

```cpp
void MonthCal_SetToday(
   HWND         hmc,
   LPSYSTEMTIME pst
);
```

## Description

Sets the "today" selection for a month calendar control. You can use this macro or send the [MCM_SETTODAY](https://learn.microsoft.com/windows/desktop/Controls/mcm-settoday) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `pst`

Type: **LPSYSTEMTIME**

Pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the date to be set as the "today" selection for the control. If this parameter is set to **NULL**, the control returns to the default setting. The time members of this structure are ignored. If the "today" selection is set to any date other than the default, the following conditions apply:

* The control will not automatically update the "today" selection when the time passes midnight for the current day.
* The control will not automatically update its display based on locale changes.