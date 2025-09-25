# MCHITTESTINFO structure

## Description

Carries information specific to hit-testing points for a month calendar control. This structure is used with the [MCM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/mcm-hittest) message and the corresponding [MonthCal_HitTest](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-monthcal_hittest) macro.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of this structure, in bytes.

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

Point to be hit-tested.

### `uHit`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Output member that receives a bit flag representing the result of the hit-test operation. This value will be one of the following:

| Value | Meaning |
| --- | --- |
| **MCHT_CALENDARBK** | The given point was in the calendar's background. |
| **MCHT_CALENDARCONTROL** | The given point is outside of any calendar but within the calendar controls [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect). |
| **MCHT_CALENDARDATE** | The given point was on a particular date within the calendar. The [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure at *lpMCHitTest*>st is set to the date at the given point. |
| **MCHT_CALENDARDATEMIN** | The given point was over the minimum date(s) in the calendar. |
| **MCHT_CALENDARDATEMAX** | The given point was over the maximum date(s) in the calendar. |
| **MCHT_CALENDARDATENEXT** | The given point was over a date from the next month (partially displayed at the end of the currently displayed month). If the user clicks here, the month calendar will scroll its display to the next month or set of months. |
| **MCHT_CALENDARDATEPREV** | The given point was over a date from the previous month (partially displayed at the end of the currently displayed month). If the user clicks here, the month calendar will scroll its display to the previous month or set of months. |
| **MCHT_CALENDARDAY** | The given point was over a day abbreviation ("Fri", for example). The [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure at *lpMCHitTest*>st is set to the corresponding date in the top row. |
| **MCHT_CALENDARWEEKNUM** | The given point was over a week number ([MCS_WEEKNUMBERS](https://learn.microsoft.com/windows/desktop/Controls/month-calendar-control-styles) style only). The [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure at *lpMCHitTest*>st is set to the corresponding date in the leftmost column. |
| **MCHT_NOWHERE** | The given point was not on the month calendar control, or it was in an inactive portion of the control. |
| **MCHT_TITLEBK** | The given point was over the background of a month's title. |
| **MCHT_TITLEBTNNEXT** | The given point was over the button at the top right corner of the control. If the user clicks here, the month calendar will scroll its display to the next month or set of months. |
| **MCHT_TITLEBTNPREV** | The given point was over the button at the top left corner of the control. If the user clicks here, the month calendar will scroll its display to the previous month or set of months. |
| **MCHT_TITLEMONTH** | The given point was in a month's title bar, over a month name. |
| **MCHT_TITLEYEAR** | The given point was in a month's title bar, over the year value. |

### `st`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

Receives date and time information specific to the location that was hit-tested.

### `rc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

Hit-tested location.

### `iOffset`

Type: **int**

When displaying more than one calendar, this is the offset of the calendar at the hit-tested point (zero-based).

### `iRow`

Type: **int**

The row number for the calendar grid that the given hit point was over. Example: If you hit-tested the 8th of a month, which is in the second week of the month, **iRow** will be one since the index of the row is zero-based row index.

### `iCol`

Type: **int**

The column number for the calendar grid that the given point was over. For example, if your week starts on Sunday and the 1st of the month is Friday, hit testing the 1st will return five (5) for **iCol**, since Friday is in the fifth column from the beginning of the row, using a zero-based column index.

## Remarks

Columns and rows in this control use a zero-based index system, that is, the first column or row has an index of zero.