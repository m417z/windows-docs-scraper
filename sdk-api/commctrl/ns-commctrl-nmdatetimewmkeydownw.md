# NMDATETIMEWMKEYDOWNW structure

## Description

Carries information used to describe and handle a [DTN_WMKEYDOWN](https://learn.microsoft.com/windows/desktop/Controls/dtn-wmkeydown) notification code.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

A [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification code.

### `nVirtKey`

Type: **int**

A virtual key code that represents the key that the user pressed.

### `pszFormat`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-terminated substring, taken from the format string, that defines the callback field. The substring is one or more "X" characters, followed by a **NULL**.

### `st`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

A [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure containing the current date and time from the DTP control. The owner of the control must modify the time information based on the user's keystroke.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMDATETIMEWMKEYDOWN as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).