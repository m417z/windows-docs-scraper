# MonthCal_SetCurSel macro

## Syntax

```cpp
BOOL MonthCal_SetCurSel(
   HWND         hmc,
   LPSYSTEMTIME pst
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise. This macro will fail if applied to a month calendar control that uses the **MCS_MULTISELECT** style.

## Description

Sets the currently selected date for a month calendar control. If the specified date is not in view, the control updates the display to bring it into view. You can use this macro or send the [MCM_SETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/mcm-setcursel) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `pst`

Type: **LPSYSTEMTIME**

Pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the date to be set as the current selection. The time members of this structure are ignored.