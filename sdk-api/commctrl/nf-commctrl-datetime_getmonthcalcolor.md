# DateTime_GetMonthCalColor macro

## Syntax

```cpp
COLORREF DateTime_GetMonthCalColor(
   HWND hdp,
   int  iColor
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **COLORREF** value that represents the color setting for the specified portion of the month calendar control if successful. Otherwise, the macro returns -1.

## Description

Gets the color for a given portion of the month calendar within a date and time picker (DTP) control. You can use this macro or send the [DTM_GETMCCOLOR](https://learn.microsoft.com/windows/desktop/Controls/dtm-getmccolor) message explicitly.

## Parameters

### `hdp`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a DTP control.

### `iColor`

Type: **int**

A value of type **int** specifying which month calendar color to retrieve. This value can be one of the following.

| Value | Meaning |
| --- | --- |
| **MCSC_BACKGROUND** | Retrieve the background color displayed between months. |
| **MCSC_MONTHBK** | Retrieve the background color displayed within the month. |
| **MCSC_TEXT** | Retrieve the color used to display text within a month. |
| **MCSC_TITLEBK** | Retrieve the background color displayed in the calendar's title. |
| **MCSC_TITLETEXT** | Retrieve the color used to display text within the calendar's title. |
| **MCSC_TRAILINGTEXT** | Retrieve the color used to display header day and trailing day text. Header and trailing days are the days from the previous and following months that appear on the current month calendar. |