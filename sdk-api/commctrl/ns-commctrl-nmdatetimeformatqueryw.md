# NMDATETIMEFORMATQUERYW structure

## Description

Contains information about a date and time picker (DTP) control callback field. It contains a substring (taken from the control's format string) that defines a callback field. The structure receives the maximum allowable size of the text that will be displayed in the callback field. This structure is used with the [DTN_FORMATQUERY](https://learn.microsoft.com/windows/desktop/Controls/dtn-formatquery) notification code.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification code.

### `pszFormat`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a substring that defines a DTP control callback field. The substring is one or more "X" characters followed by a **NULL**. (For additional information about callback fields, see [Callback fields](https://learn.microsoft.com/windows/desktop/Controls/date-and-time-picker-controls).)

### `szMax`

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)**

A [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that must be filled with the maximum size of the text that will be displayed in the callback field.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMDATETIMEFORMATQUERY as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).