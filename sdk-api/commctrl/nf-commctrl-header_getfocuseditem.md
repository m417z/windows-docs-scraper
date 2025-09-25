# Header_GetFocusedItem macro

## Syntax

```cpp
int Header_GetFocusedItem(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns the index of the item in focus.

## Description

Gets the item in a header control that has the focus. Use this macro or send the [HDM_GETFOCUSEDITEM](https://learn.microsoft.com/windows/desktop/Controls/hdm-getfocuseditem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

## See also

[About Header Controls](https://learn.microsoft.com/windows/desktop/Controls/header-controls)