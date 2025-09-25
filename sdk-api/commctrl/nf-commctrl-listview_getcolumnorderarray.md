# ListView_GetColumnOrderArray macro

## Syntax

```cpp
BOOL ListView_GetColumnOrderArray(
   HWND hwnd,
   int  iCount,
   int  *pi
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If successful, returns nonzero and the buffer at *lpiArray* receives the column index of each column in the control in the order they appear from left to right. Otherwise, the return value is zero.

## Description

Gets the current left-to-right order of columns in a list-view control. You can use this macro or send the [LVM_GETCOLUMNORDERARRAY](https://learn.microsoft.com/windows/desktop/Controls/lvm-getcolumnorderarray) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `iCount`

Type: **int**

The number of columns in the list-view control.

### `pi`

Type: **int***

A pointer to an array of integers that will receive the index values of the columns in the list-view control. The array must be large enough to hold
*iCount* elements.