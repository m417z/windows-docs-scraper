# Header_SetFocusedItem macro

## Syntax

```cpp
BOOL Header_SetFocusedItem(
  [in] HWND hwnd,
  [in] int  iItem
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets the focus to a specified item in a header control. Use this macro or send the [HDM_SETFOCUSEDITEM](https://learn.microsoft.com/windows/desktop/Controls/hdm-setfocuseditem) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

### `iItem` [in]

Type: **int**

The index of item.

## See also

[About Header Controls](https://learn.microsoft.com/windows/desktop/Controls/header-controls)