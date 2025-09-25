# Pager_GetButtonState macro

## Syntax

```cpp
DWORD Pager_GetButtonState(
   HWND hwnd,
   int  iButton
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the state of the button specified in *iButton*. See the return value description in **PGM_GETBUTTONSTATE** for a list of possible values.

## Description

Retrieves the state of the specified button in a pager control. You can use this macro or send the [PGM_GETBUTTONSTATE](https://learn.microsoft.com/windows/desktop/Controls/pgm-getbuttonstate) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.

### `iButton`

Type: **int**

Indicates which button to retrieve the state for. See the description for *iButton* in [PGM_GETBUTTONSTATE](https://learn.microsoft.com/windows/desktop/Controls/pgm-getbuttonstate) for a list of possible values.