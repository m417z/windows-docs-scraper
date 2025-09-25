# Button_SetStyle macro

## Syntax

```cpp
LRESULT Button_SetStyle(
   HWND  hwndCtl,
   DWORD style,
   BOOL  fRedraw
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is always zero.

## Description

Sets the style of a button. You can use this macro or send the [BM_SETSTYLE](https://learn.microsoft.com/windows/desktop/Controls/bm-setstyle) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `style`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The button style. This parameter can be a combination of button styles. For a table of button styles, see [Button Styles](https://learn.microsoft.com/windows/desktop/Controls/button-styles).

### `fRedraw`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to redraw the button; otherwise **FALSE**.