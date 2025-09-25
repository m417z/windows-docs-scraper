# DateTime_GetRange macro

## Syntax

```cpp
DWORD DateTime_GetRange(
   HWND         hdp,
   LPSYSTEMTIME rgst
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **DWORD** value that is a combination of GDTR_MIN or GDTR_MAX. The first element of the **SYSTEMTIME** array contains the minimum allowable time. The second element of the **SYSTEMTIME** array contains the maximum allowable time.

## Description

Gets the current minimum and maximum allowable system times for a date and time picker (DTP) control. You can use this macro, or send the [DTM_GETRANGE](https://learn.microsoft.com/windows/desktop/Controls/dtm-getrange) message explicitly.

## Parameters

### `hdp`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a DTP control.

### `rgst`

Type: **LPSYSTEMTIME**

A pointer to a two-element array of [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structures.

## Remarks

The date and time picker displays only dates/times that fall within the specified range, preventing the user from selecting a date and time that falls outside the range. If the [DateTime_SetSystemtime](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-datetime_setsystemtime) message specifies a date and time that falls outside the range, it will fail.