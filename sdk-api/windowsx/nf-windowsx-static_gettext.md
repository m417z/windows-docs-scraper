# Static_GetText macro

## Syntax

```cpp
int Static_GetText(
   HWND   hwndCtl,
   LPTSTR lpch,
   int    cchMax
);
```

## Return value

Type: **int**

The length, in characters, of the copied string, not including the terminating NULL character.

## Description

Gets the text of a static control.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `lpch`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the buffer that will receive the text.

### `cchMax`

Type: **int**

The maximum number of characters to copy to the buffer, including the NULL terminator.

## Remarks

The macro expands to a call to [GetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtexta).