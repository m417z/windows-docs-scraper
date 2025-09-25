# Edit_GetSel macro

## Syntax

```cpp
DWORD Edit_GetSel(
   HWND hwndCtl
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is a zero-based value with the starting position of the selection in the **LOWORD** and the position of the first character after the last selected character in the **HIWORD**. If either of these values exceeds 65,535, the return value is –1.

## Description

Gets the starting and ending character positions of the current selection in an edit or rich edit control. You can use this macro or send the [EM_GETSEL](https://learn.microsoft.com/windows/desktop/Controls/em-getsel) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

This macro does not have the complete functionality of the [EM_GETSEL](https://learn.microsoft.com/windows/desktop/Controls/em-getsel) message, because it does not receive the 32-bit return values in the parameters of [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage).