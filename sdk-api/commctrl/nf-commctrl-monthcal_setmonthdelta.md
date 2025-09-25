# MonthCal_SetMonthDelta macro

## Syntax

```cpp
INT MonthCal_SetMonthDelta(
   HWND hmc,
   INT  n
);
```

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns an INT value that represents the previous scroll rate. If the scroll rate was not previously set, the return value is zero.

## Description

Sets the scroll rate for a month calendar control. The scroll rate is the number of months that the control moves its display when the user clicks a scroll button. You can use this macro or send the [MCM_SETMONTHDELTA](https://learn.microsoft.com/windows/desktop/Controls/mcm-setmonthdelta) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `n`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value representing the number of months to be set as the control's scroll rate. If this value is zero, the month delta is reset to the default, which is the number of months displayed in the control.

## Remarks

The PAGE UP and PAGE DOWN keys, VK_PRIOR and VK_NEXT, change the selected month by one, regardless of the number of months displayed or the value set by [MCM_SETMONTHDELTA](https://learn.microsoft.com/windows/desktop/Controls/mcm-setmonthdelta).