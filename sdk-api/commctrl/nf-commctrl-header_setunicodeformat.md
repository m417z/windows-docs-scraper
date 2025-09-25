# Header_SetUnicodeFormat macro

## Syntax

```cpp
BOOL Header_SetUnicodeFormat(
   HWND hwnd,
   BOOL fUnicode
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the previous Unicode format flag for the control.

## Description

Sets the UNICODE character format flag for the control. This message allows you to change the character set used by the control at run time rather than having to re-create the control. You can use this macro or send the [HDM_SETUNICODEFORMAT](https://learn.microsoft.com/windows/desktop/Controls/hdm-setunicodeformat) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `fUnicode`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Determines the character set that is used by the control. If this value is nonzero, the control will use Unicode characters. If this value is zero, the control will use ANSI characters.

## See also

[Header_GetUnicodeFormat](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-header_getunicodeformat)