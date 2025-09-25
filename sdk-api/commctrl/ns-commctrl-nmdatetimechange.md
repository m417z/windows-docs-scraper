# NMDATETIMECHANGE structure

## Description

Contains information about a change that has taken place in a date and time picker (DTP) control. This structure is used with the [DTN_DATETIMECHANGE](https://learn.microsoft.com/windows/desktop/Controls/dtn-datetimechange) notification code.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification code.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that indicates if the control was set to "no date" status (for [DTS_SHOWNONE](https://learn.microsoft.com/windows/desktop/Controls/date-and-time-picker-control-styles) only). This flag also specifies whether the contents of the **st** member are valid and contain current time information. This value can be one of the following:

| Value | Meaning |
| --- | --- |
| **GDT_NONE** | The control is set to "no date" status. The "no date" status applies only to controls that are set to the [DTS_SHOWNONE](https://learn.microsoft.com/windows/desktop/Controls/date-and-time-picker-control-styles) style. |
| **GDT_VALID** | The control is not set to the "no date" status. The **st** member contains the current date and time. |

### `st`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

A [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains information about the current system date and time.