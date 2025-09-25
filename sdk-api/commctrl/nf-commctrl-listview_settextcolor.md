# ListView_SetTextColor macro

## Syntax

```cpp
BOOL ListView_SetTextColor(
   HWND     hwnd,
   COLORREF clrText
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets the text color of a list-view control. You can use this macro or send the [LVM_SETTEXTCOLOR](https://learn.microsoft.com/windows/desktop/Controls/lvm-settextcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `clrText`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The new text color.