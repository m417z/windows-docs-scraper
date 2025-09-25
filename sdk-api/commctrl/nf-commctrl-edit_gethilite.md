# Edit_GetHilite macro

## Syntax

```cpp
DWORD Edit_GetHilite(
   HWND hwndCtl
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The starting and ending indexes that are highlighted. This value was created with the **MAKELONG** macro, with the starting index as the low word and the ending index as the high word. So, to get the starting index, call the **LOWORD** macro with the return value and to get the ending index, call the **HIWORD** macro with the return value.

## Description

This macro is not implemented.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the edit control.