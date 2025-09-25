# MonthCal_GetCurSel macro

## Syntax

```cpp
BOOL MonthCal_GetCurSel(
   HWND         hmc,
   LPSYSTEMTIME pst
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise. This macro will always fail when applied to month calendar controls that are set to the **MCS_MULTISELECT** style.

## Description

Retrieves the currently selected date. You can use this macro or send the [MCM_GETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/mcm-getcursel) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `pst`

Type: **LPSYSTEMTIME**

Pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that will receive the currently selected date information. This parameter must be a valid address and cannot be **NULL**.