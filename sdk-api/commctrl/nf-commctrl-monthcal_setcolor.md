# MonthCal_SetColor macro

## Syntax

```cpp
COLORREF MonthCal_SetColor(
   HWND     hmc,
   INT      iColor,
   COLORREF clr
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **COLORREF** value that represents the previous color setting for the specified portion of the month calendar control if successful. Otherwise, the return is -1.

## Description

Sets the color for a given portion of a month calendar control. You can use this macro or send the [MCM_SETCOLOR](https://learn.microsoft.com/windows/desktop/Controls/mcm-setcolor) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `iColor`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value of type **int** specifying which month calendar color to set. This value can be one of the following:

| Value | Meaning |
| --- | --- |
| **MCSC_BACKGROUND** | Set the background color displayed between months. |
| **MCSC_MONTHBK** | Set the background color displayed within the month. |
| **MCSC_TEXT** | Set the color used to display text within a month. |
| **MCSC_TITLEBK** | Set the background color displayed in the calendar's title. |
| **MCSC_TITLETEXT** | Set the color used to display text within the calendar's title. |
| **MCSC_TRAILINGTEXT** | Set the color used to display header day and trailing day text. Header and trailing days are the days from the previous and following months that appear on the current month calendar. |

### `clr`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**COLORREF** value that represents the color that will be set for the specified area of the month calendar.

## Remarks

If visual styles are active, this macro has no effect except when *iColor* is MCSC_BACKGROUND.