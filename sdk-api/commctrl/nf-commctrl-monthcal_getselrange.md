# MonthCal_GetSelRange macro

## Syntax

```cpp
BOOL MonthCal_GetSelRange(
   HWND         hmc,
   LPSYSTEMTIME rgst
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise. **MonthCal_GetSelRange** will fail if applied to a month calendar control that does not use the **MCS_MULTISELECT** style.

## Description

Retrieves date information that represents the upper and lower limits of the date range currently selected by the user. You can use this macro or send the [MCM_GETSELRANGE](https://learn.microsoft.com/windows/desktop/Controls/mcm-getselrange) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `rgst`

Type: **LPSYSTEMTIME**

Pointer to a two-element array of [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structures that will receive the lower and upper limits of the user's selection. The lower and upper limits are placed in *rgst*[0] and *rgst*[1], respectively. The time members of these structures will not be modified. This parameter must be a valid address and cannot be **NULL**.