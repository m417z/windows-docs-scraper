# MonthCal_SizeRectToMin macro

## Syntax

```cpp
LRESULT MonthCal_SizeRectToMin(
            HWND hmc,
  [in, out] RECT prc
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Unused.

## Description

Calculates how many calendars will fit in the given rectangle, and then returns the minimum size that a rectangle needs to be to fit that number of calendars. You can use this macro or send the [MCM_SIZERECTTOMIN](https://learn.microsoft.com/windows/desktop/Controls/mcm-sizerecttomin) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `prc` [in, out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

On entry, contains a pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that describes a region that is greater than or equal to the size necessary to fit the desired number of calendars. When this function returns, contains the minimum **RECT** structure that fits this number of calendars.