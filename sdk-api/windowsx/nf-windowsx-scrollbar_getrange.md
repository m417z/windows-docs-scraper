# ScrollBar_GetRange macro

## Syntax

```cpp
BOOL ScrollBar_GetRange(
   HWND hwndCtl,
   int  *lpposMin,
   int  *lpposMax
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if the call succeeded; otherwise **FALSE**.

## Description

Gets the range of a scroll bar.

**Note** This macro expands to a call to the [GetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollrange) function, which is deprecated. New applications should use the [GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo) function.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `lpposMin`

Type: **int***

Address of a variable that receives the minimum value of the scroll bar.

### `lpposMax`

Type: **int***

Address of a variable that receives the maximum value of the scroll bar.

## Remarks

For more information, see [GetScrollRange](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollrange).