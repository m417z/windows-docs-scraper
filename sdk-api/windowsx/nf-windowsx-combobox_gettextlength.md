# ComboBox_GetTextLength macro

## Syntax

```cpp
int ComboBox_GetTextLength(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The length, in characters, of the text.

## Description

Gets the number of characters in the text of a combo box.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

The macro expands to a call to [GetWindowTextLength](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtextlengtha).