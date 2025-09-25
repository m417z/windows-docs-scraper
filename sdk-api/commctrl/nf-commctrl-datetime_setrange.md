# DateTime_SetRange macro

## Syntax

```cpp
BOOL DateTime_SetRange(
   HWND         hdp,
   DWORD        gd,
   LPSYSTEMTIME rgst
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Sets the minimum and maximum allowable system times for a date and time picker (DTP) control. You can use this macro or send the [DTM_SETRANGE](https://learn.microsoft.com/windows/desktop/Controls/dtm-setrange) message explicitly.

## Parameters

### `hdp`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a DTP control.

### `gd`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that specifies which range values are valid. This value can be a combination of the following:

| Value | Meaning |
| --- | --- |
| **GDTR_MIN** | The first element in the [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure array is valid and will be used to set the minimum allowable system time. |
| **GDTR_MAX** | The second element in the [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure array is valid and will be used to set the maximum allowable system time. |

### `rgst`

Type: **LPSYSTEMTIME**

A pointer to a two-element array of [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structures. The first element of the **SYSTEMTIME** array contains the minimum allowable time. The second element of the **SYSTEMTIME** array contains the maximum allowable time. It is not necessary to fill an array element that is not specified in the *gd* parameter.

## Remarks

The date and time picker displays only dates/times that fall within the specified range, preventing the user from selecting a date and time that falls outside the range. If the [DateTime_SetSystemtime](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-datetime_setsystemtime) message specifies a date and time that falls outside the range, it will fail.