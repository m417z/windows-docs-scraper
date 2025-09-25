# Header_Layout macro

## Syntax

```cpp
BOOL Header_Layout(
  [in]  HWND       hwndHD,
  [out] LPHDLAYOUT playout
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Retrieves the correct size and position of a header control within the parent window. You can use this macro or send the [HDM_LAYOUT](https://learn.microsoft.com/windows/desktop/Controls/hdm-layout) message explicitly.

## Parameters

### `hwndHD` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

### `playout` [out]

Type: **LPHDLAYOUT**

A pointer to an [HDLAYOUT](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-hdlayout) structure. The
**prc** member specifies the coordinates of a rectangle, and the
**pwpos** member receives the size and position for the header control within the rectangle.

## Remarks

The **Header_Layout** macro is defined as follows:

``` syntax
#define Header_Layout(hwndHD, playout) \

    (BOOL)SendMessage((hwndHD), HDM_LAYOUT, 0, \

    (LPARAM)(LPHDLAYOUT)(playout))
```