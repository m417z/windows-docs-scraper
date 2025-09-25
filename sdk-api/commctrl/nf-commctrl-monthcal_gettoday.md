# MonthCal_GetToday macro

## Syntax

```cpp
BOOL MonthCal_GetToday(
   HWND         hmc,
   LPSYSTEMTIME pst
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Retrieves the date information for the date specified as "today" for a month calendar control. You can use this macro or send the [MCM_GETTODAY](https://learn.microsoft.com/windows/desktop/Controls/mcm-gettoday) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `pst`

Type: **LPSYSTEMTIME**

Pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that will receive the date information. The time members of this structure will not be modified. This parameter must be a valid address and cannot be **NULL**.