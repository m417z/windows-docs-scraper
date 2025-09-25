# MonthCal_GetMonthRange macro

## Syntax

```cpp
INT MonthCal_GetMonthRange(
   HWND         hmc,
   DWORD        gmr,
   LPSYSTEMTIME rgst
);
```

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns an INT value that represents the range, in months, spanned by the two limits returned at *rgst*.

## Description

Retrieves date information (using [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structures) that represents the high and low limits of a month calendar control's display. You can use this macro or send the [MCM_GETMONTHRANGE](https://learn.microsoft.com/windows/desktop/Controls/mcm-getmonthrange) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `gmr`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specifying the scope of the range limits to be retrieved. This value must be one of the following:

| Value | Meaning |
| --- | --- |
| **GMR_DAYSTATE** | Include preceding and trailing months of visible range that are only partially displayed. |
| **GMR_VISIBLE** | Include only those months that are entirely displayed. |

### `rgst`

Type: **LPSYSTEMTIME**

Pointer to a two-element array of [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structures that will receive the lower and upper limits of the scope specified by *gmr*. The lower and upper limits are placed in rgst[0] and rgst[1], respectively. The time members of these structures will not be modified. This parameter must be a valid address and cannot be **NULL**.