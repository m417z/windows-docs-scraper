# ScrollBar_SetRange macro

## Syntax

```cpp
BOOL ScrollBar_SetRange(
   HWND hwndCtl,
   int  posMin,
   int  posMax,
   BOOL fRedraw
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if the call succeeded; otherwise **FALSE**.

## Description

Sets the range of a scroll bar.

**Note** This macro expands to a call to the [SetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollrange) function, which is deprecated. New applications should use the [SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo) function.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `posMin`

Type: **int**

The minimum value of the scroll bar.

### `posMax`

Type: **int**

The maximum value of the scroll bar.

### `fRedraw`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to redraw the control; otherwise **FALSE**.

## Remarks

For more information, see [SetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollrange).