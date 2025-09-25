# MonthCal_SetRange macro

## Syntax

```cpp
BOOL MonthCal_SetRange(
   HWND         hmc,
   DWORD        gd,
   LPSYSTEMTIME rgst
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Sets the minimum and maximum allowable dates for a month calendar control. You can use this macro or send the [MCM_SETRANGE](https://learn.microsoft.com/windows/desktop/Controls/mcm-setrange) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `gd`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag values that specify which date limits are being set. This value must be one or both of the following:

| Value | Meaning |
| --- | --- |
| **GDTR_MAX** | The maximum allowable date is being set. The [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure at *rgst*[1] must contain date information. |
| **GDTR_MIN** | The minimum allowable date is being set. The [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure at *rgst*[0] must contain date information. |

### `rgst`

Type: **LPSYSTEMTIME**

Pointer to a two-element array of [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structures that contain the date limits. The maximum limit must be in *rgst*[1] if GDTR_MAX is specified, and *rgst*[0] must contain the minimum limit if GDTR_MIN is specified.