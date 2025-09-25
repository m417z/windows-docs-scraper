# MCGRIDINFO structure

## Description

Contains information about part of a calendar control.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of this structure, in bytes.

### `dwPart`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The part of the calendar control for which information is being requested. One of the following values.

| Value | Meaning |
| --- | --- |
| **MCGIP_CALENDARCONTROL** | The entire calendar control, which may include up to 12 calendars. |
| **MCGIP_NEXT** | The next button. |
| **MCGIP_PREV** | The previous button. |
| **MCGIP_FOOTER** | The footer. |
| **MCGIP_CALENDAR** | One specific calendar. Used with **iCalendar** and **pszName**. |
| **MCGIP_CALENDARHEADER** | Calendar header. Used with **iCalendar** and **pszName**. |
| **MCGIP_CALENDARBODY** | Calendar body. Used with **iCalendar**. |
| **MCGIP_CALENDARROW** | A given calendar row. Used with **iCalendar** and **iRow**. |
| **MCGIP_CALENDARCELL** | A given calendar cell. Used with **iCalendar**, **iRow**, **iCol**, **bSelected** and **pszName**. |

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates what information is to be filled in. A combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MCGIF_DATE** | **stStart** and **stEnd**. |
| **MCGIF_RECT** | **rc**. |
| **MCGIF_NAME** | **pszName**. |

### `iCalendar`

Type: **int**

If **dwPart** is MCGIP_CALENDAR, MCGIP_CALENDARHEADER, MCGIP_CALENDARBODY, MCGIP_CALENDARROW, or MCGIP_CALENDARCELL, this member specifies the index of the calendar for which to retrieve information. For those parts, this must be a valid value even if there is only one calendar that is currently in the control.

### `iRow`

Type: **int**

If **dwPart** is MCGIP_CALENDARROW, specifies the row for which to return information.

### `iCol`

Type: **int**

If **dwPart** is MCGIP_CALENDARCELL, specifies the column of the cell for which to return information. The **iRow** member provides the row of the cell for which to return information.

### `bSelected`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **dwPart** is MCGIP_CALENDARCELL, indicates if the cell described by **iRow** and **iCol** is currently selected.

### `stStart`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

Returns the start date specified by iCalendar. Used only when **dwFlags** contains MCGIF_DATE.

### `stEnd`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

Returns the end date specified by iCalendar. Used only when **dwFlags** contains MCGIF_DATE.

### `rc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

Returns the rectangle of the part specified in **dwPart**. Set only if **dwFlags** contains MCGIF_RECT.

### `pszName`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string for which **cchName** is the length. Set only if **dwFlags** contains MCGIF_NAME, and only for the following parts, as described in the **dwPart** member.

* MCGIP_CALENDAR: Returns the text of the selected dates. In the case of multiple selection, returns the date at the start of the selection.
* MCGIP_CALENDARCELL: Returns the text of the cell indicated by **iRow** and **iCol**, for instance "11" if the 11th day was specified.
* MCGIP_CALENDARHEADER: Returns the text of what it says in the calendar header, for instance "July, 2006".

### `cchName`

Type: **size_t**

Length of **pszName**, in characters.