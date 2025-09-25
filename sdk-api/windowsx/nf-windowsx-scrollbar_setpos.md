# ScrollBar_SetPos macro

## Syntax

```cpp
BOOL ScrollBar_SetPos(
   HWND hwndCtl,
   int  pos,
   BOOL fRedraw
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

See **SetScrollPos**.

## Description

Sets the position of the scroll box (thumb) in the specified scroll bar and, if requested, redraws the scroll bar to reflect the new position of the scroll box.

**Note** This macro expands to a call to the [SetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollpos) function, which is deprecated. New applications should use the [SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo) function.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `pos`

Type: **int**

The new position of the scroll box.

### `fRedraw`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to redraw the control; otherwise **FALSE**.