# NMDATETIMESTRINGA structure

## Description

Contains information specific to an edit operation that has taken place in a date and time picker (DTP) control. This message is used with the [DTN_USERSTRING](https://learn.microsoft.com/windows/desktop/Controls/dtn-userstring) notification code.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification code.

### `pszUserString`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The address of the zero-terminated string that the user entered.

### `st`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

A [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that must be filled in by the owner when handling the [DTN_USERSTRING](https://learn.microsoft.com/windows/desktop/Controls/dtn-userstring) notification code.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return field. Set this member to GDT_VALID to indicate that the
**st** member is valid or to GDT_NONE to set the control to "no date" status ([DTS_SHOWNONE](https://learn.microsoft.com/windows/desktop/Controls/date-and-time-picker-control-styles) style only).

## Remarks

> [!NOTE]
> The commctrl.h header defines NMDATETIMESTRING as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).