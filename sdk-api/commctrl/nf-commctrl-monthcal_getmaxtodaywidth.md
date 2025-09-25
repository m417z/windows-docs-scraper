# MonthCal_GetMaxTodayWidth macro

## Syntax

```cpp
DWORD MonthCal_GetMaxTodayWidth(
   HWND hmc
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the width of the "today" string, in pixels.

## Description

Retrieves the maximum width of the "today" string in a month calendar control. This includes the label text and the date text. You can use this macro or send the [MCM_GETMAXTODAYWIDTH](https://learn.microsoft.com/windows/desktop/Controls/mcm-getmaxtodaywidth) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.