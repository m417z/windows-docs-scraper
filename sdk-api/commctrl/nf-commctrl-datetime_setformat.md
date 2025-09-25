# DateTime_SetFormat macro

## Syntax

```cpp
void DateTime_SetFormat(
   HWND    hdp,
   LPCTSTR sz
);
```

## Description

Sets the display of a date and time picker (DTP) control based on a given format string. You can use this macro or send the [DTM_SETFORMAT](https://learn.microsoft.com/windows/desktop/Controls/dtm-setformat) message explicitly.

## Parameters

### `hdp`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a DTP control.

### `sz`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a zero-terminated [format string](https://learn.microsoft.com/windows/desktop/Controls/date-and-time-picker-controls) that defines the desired display. Setting this parameter to **NULL** will reset the control to the default format string for the current style.

## Remarks

It is acceptable to include extra characters within the format string to produce a more rich display. However, any nonformat characters must be enclosed within single quotes. For example, the format string "'Today is: 'hh':'m':'s ddddMMMdd', 'yyy" would produce output like "Today is: 04:22:31 Tuesday Mar 23, 1996".

**Note** A DTP control tracks locale changes when it is using the default format string. If you set a custom format string, it will not be updated in response to locale changes.