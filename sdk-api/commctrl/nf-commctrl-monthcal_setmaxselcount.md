# MonthCal_SetMaxSelCount macro

## Syntax

```cpp
BOOL MonthCal_SetMaxSelCount(
   HWND hmc,
   UINT n
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise. This macro will fail if applied to a month calendar control that does not use the **MCS_MULTISELECT** style.

## Description

Sets the maximum number of days that can be selected in a month calendar control. You can use this macro or send the [MCM_SETMAXSELCOUNT](https://learn.microsoft.com/windows/desktop/Controls/mcm-setmaxselcount) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `n`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value of type **int** that will be set to represent the maximum number of days that can be selected.