# MonthCal_GetMaxSelCount macro

## Syntax

```cpp
DWORD MonthCal_GetMaxSelCount(
   HWND hmc
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns an INT value that represents the total number of days that can be selected for the control.

## Description

Retrieves the maximum date range that can be selected in a month calendar control. You can use this macro or send the [MCM_GETMAXSELCOUNT](https://learn.microsoft.com/windows/desktop/Controls/mcm-getmaxselcount) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

## Remarks

You can change the maximum date range that can be selected by using the [MCM_SETMAXSELCOUNT](https://learn.microsoft.com/windows/desktop/Controls/mcm-setmaxselcount) message.