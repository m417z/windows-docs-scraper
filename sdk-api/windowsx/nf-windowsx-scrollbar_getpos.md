# ScrollBar_GetPos macro

## Syntax

```cpp
int ScrollBar_GetPos(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The current position of the scroll bar.

## Description

Retrieves the position of the scroll box (thumb) in the specified scroll bar.

**Note** This macro expands to a call to the [GetScrollPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollpos) function, which is deprecated. New applications should use the [GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo) function.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo).