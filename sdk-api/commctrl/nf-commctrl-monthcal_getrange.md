# MonthCal_GetRange macro

## Syntax

```cpp
DWORD MonthCal_GetRange(
   HWND         hmc,
   LPSYSTEMTIME rgst
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **DWORD** value that can be zero (no limits are set) or a combination of the following values that specify limit information:

| Return code | Description |
|---|---|
| GDTR_MAX | There is a maximum limit set for the control; rgst[0] is valid and contains the applicable date information. |
| GDTR_MIN | There is a minimum limit set for the control; rgst[1] is valid and contains the applicable date information. |

## Description

Retrieves the minimum and maximum allowable dates set for a month calendar control. You can use this macro or send the [MCM_GETRANGE](https://learn.microsoft.com/windows/desktop/Controls/mcm-getrange) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `rgst`

Type: **LPSYSTEMTIME**

Pointer to a two-element array of [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structures that will receive the date limit information. The minimum limit is set in *rgst*[0], and *rgst*[1] receives the maximum limit. If either element is set to all zeros, then no corresponding limit is set for the month calendar control. The time members of these structures will not be modified. This parameter must be a valid address and cannot be **NULL**.