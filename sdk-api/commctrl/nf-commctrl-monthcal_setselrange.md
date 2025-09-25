# MonthCal_SetSelRange macro

## Syntax

```cpp
BOOL MonthCal_SetSelRange(
   HWND         hmc,
   LPSYSTEMTIME rgst
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise. This macro will fail if applied to a month calendar control that does not use the **MCS_MULTISELECT** style.

## Description

Sets the selection for a month calendar control to a given date range. You can use this macro or send the [MCM_SETSELRANGE](https://learn.microsoft.com/windows/desktop/Controls/mcm-setselrange) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `rgst`

Type: **LPSYSTEMTIME**

Pointer to a two-element array of [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structures that contain date information representing the selection limits. The first selected date must be specified in *rgst*[0], and the last selected date must be specified in *rgst*[1]. The time members of these structures are ignored.