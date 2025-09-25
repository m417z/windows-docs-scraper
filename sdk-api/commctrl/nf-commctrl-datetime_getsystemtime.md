# DateTime_GetSystemtime macro

## Syntax

```cpp
DWORD DateTime_GetSystemtime(
   HWND         hdp,
   LPSYSTEMTIME pst
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns GDT_VALID if the time information was successfully placed in *pst*. Returns GDT_NONE if the control was set to the **DTS_SHOWNONE** style and the control check box was not selected. Returns GDT_ERROR if an error occurs.

## Description

Gets the currently selected time from a date and time picker (DTP) control and places it in a specified [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure. You can use this macro, or send the [DTM_GETSYSTEMTIME](https://learn.microsoft.com/windows/desktop/Controls/dtm-getsystemtime) message explicitly.

## Parameters

### `hdp`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a DTP control.

### `pst`

Type: **LPSYSTEMTIME**

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure. If [DTM_GETSYSTEMTIME](https://learn.microsoft.com/windows/desktop/Controls/dtm-getsystemtime) returns GDT_VALID, this structure will contain the currently selected time. Otherwise, it will not contain valid information. This parameter must be a valid pointer; it cannot be **NULL**.