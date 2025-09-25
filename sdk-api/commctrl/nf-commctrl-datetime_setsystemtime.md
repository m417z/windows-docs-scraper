# DateTime_SetSystemtime macro

## Syntax

```cpp
BOOL DateTime_SetSystemtime(
   HWND         hdp,
   DWORD        gd,
   LPSYSTEMTIME pst
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Sets a date and time picker (DTP) control to a given date and time. You can use this macro or send the [DTM_SETSYSTEMTIME](https://learn.microsoft.com/windows/desktop/Controls/dtm-setsystemtime) message explicitly.

## Parameters

### `hdp`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a DTP control.

### `gd`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that specifies the action that should be performed. This should be set to one of the following values.

| Value | Meaning |
| --- | --- |
| **GDT_VALID** | Set the DTP control according to the data within the [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure pointed to by *pst*. |
| **GDT_NONE** | Set the DTP control to "no date" and clear its check box. When this flag is specified, *pst* is ignored. This flag applies only to DTP controls that are set to the [DTS_SHOWNONE](https://learn.microsoft.com/windows/desktop/Controls/date-and-time-picker-control-styles) style. |

### `pst`

Type: **LPSYSTEMTIME**

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the system time information by which to set the DTP control.