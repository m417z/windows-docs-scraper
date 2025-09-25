# Button_SetText macro

## Syntax

```cpp
int Button_SetText(
   HWND   hwndCtl,
   LPTSTR lpsz
);
```

## Return value

Type: **int**

If the function succeeds, the return value is nonzero. If it fails, the return value is zero.

## Description

Sets the text of a button.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `lpsz`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated string to be used as the button text.

## Remarks

The macro expands to a call to [SetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowtexta).