# ListView_SetColumnOrderArray macro

## Syntax

```cpp
BOOL ListView_SetColumnOrderArray(
   HWND hwnd,
   int  iCount,
   int  *pi
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Sets the left-to-right order of columns in a list-view control. You can use this macro or send the [LVM_SETCOLUMNORDERARRAY](https://learn.microsoft.com/windows/desktop/Controls/lvm-setcolumnorderarray) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `iCount`

Type: **int**

The number of columns in the list-view control.

### `pi`

Type: **int***

A pointer to an array specifying the order in which columns should be displayed, from left to right. For example, if the contents of the array are {2,0,1}, the control displays column 2, column 0, and column 1, from left to right.