# NMDATETIMEFORMATW structure

## Description

Contains information about a portion of the format string that defines a callback field within a date and time picker (DTP) control. It carries the substring that defines the callback field and contains a buffer to receive the string that will be displayed in the callback field. This structure is used with the [DTN_FORMAT](https://learn.microsoft.com/windows/desktop/Controls/dtn-format) notification code.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification code.

### `pszFormat`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the substring that defines a DTP control callback field. The substring consists of one or more "X" characters followed by a NULL character. (For more information about callback fields, see [Callback fields](https://learn.microsoft.com/windows/desktop/Controls/date-and-time-picker-controls).)

### `st`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

A [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the date and time to be formatted.

### `pszDisplay`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated string that contains the display text of the control. By default, this is the address of the
**szDisplay** member of this structure. It is acceptable to have **pszDisplay** point to an existing string. In this case, you do not need to assign a value to **szDisplay**. However, the string that
**pszDisplay** points to must remain valid until another [DTN_FORMAT](https://learn.microsoft.com/windows/desktop/Controls/dtn-format) notification is sent, or until the control is destroyed.

### `szDisplay`

Type: **[TCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

64-character buffer that is to receive the zero-terminated string that the DTP control will display. It is not necessary to fill the entire buffer.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMDATETIMEFORMAT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).