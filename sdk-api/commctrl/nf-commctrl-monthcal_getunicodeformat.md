# MonthCal_GetUnicodeFormat macro

## Syntax

```cpp
BOOL MonthCal_GetUnicodeFormat(
   HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the Unicode format flag for the control. If this value is nonzero, the control is using Unicode characters. If this value is zero, the control is using ANSI characters.

## Description

Retrieves the Unicode character format flag for the control. You can use this macro or send the [MCM_GETUNICODEFORMAT](https://learn.microsoft.com/windows/desktop/Controls/mcm-getunicodeformat) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the control.

## See also

[MonthCal_SetUnicodeFormat](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-monthcal_setunicodeformat)