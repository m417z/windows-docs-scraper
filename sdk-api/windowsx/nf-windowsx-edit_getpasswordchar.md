# Edit_GetPasswordChar macro

## Syntax

```cpp
TCHAR Edit_GetPasswordChar(
   HWND hwndCtl
);
```

## Return value

Type: **[TCHAR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The password character.

## Description

Gets the password character for an edit or rich edit control. You can use this macro or send the [EM_GETPASSWORDCHAR](https://learn.microsoft.com/windows/desktop/Controls/em-getpasswordchar) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [EM_GETPASSWORDCHAR](https://learn.microsoft.com/windows/desktop/Controls/em-getpasswordchar).