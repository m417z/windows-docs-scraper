# Edit_SetPasswordChar macro

## Syntax

```cpp
void Edit_SetPasswordChar(
   HWND hwndCtl,
   UINT ch
);
```

## Description

Sets or removes the password character for an edit or rich edit control. When a password character is set, that character is displayed in place of the characters typed by the user. You can use this macro or send the [EM_SETPASSWORDCHAR](https://learn.microsoft.com/windows/desktop/Controls/em-setpasswordchar) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `ch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The character to be displayed in place of the characters typed by the user. If this parameter is zero, the control removes the current password character and displays the characters typed by the user.

## Remarks

For more information, see [EM_SETPASSWORDCHAR](https://learn.microsoft.com/windows/desktop/Controls/em-setpasswordchar).