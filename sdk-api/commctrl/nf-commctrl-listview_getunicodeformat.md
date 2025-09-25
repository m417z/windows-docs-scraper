# ListView_GetUnicodeFormat macro

## Syntax

```cpp
BOOL ListView_GetUnicodeFormat(
   HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the Unicode format flag for the control. If this value is nonzero, the control is using Unicode characters. If this value is zero, the control is using ANSI characters.

## Description

Gets the Unicode character format flag for the control. You can use this macro or send the [LVM_GETUNICODEFORMAT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getunicodeformat) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## See also

[ListView_SetUnicodeFormat](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setunicodeformat)