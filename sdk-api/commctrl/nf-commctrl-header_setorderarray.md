# Header_SetOrderArray macro

## Syntax

```cpp
BOOL Header_SetOrderArray(
   HWND hwnd,
   int  iCount,
   int  *lpi
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Sets the left-to-right order of header items. You can use this macro or send the [HDM_SETORDERARRAY](https://learn.microsoft.com/windows/desktop/Controls/hdm-setorderarray) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.

### `iCount`

Type: **int**

The size of the buffer at
*lpiArray*, in elements. This value must equal the value returned by [HDM_GETITEMCOUNT](https://learn.microsoft.com/windows/desktop/Controls/hdm-getitemcount).

### `lpi`

Type: **int***

A pointer to an array that specifies the order in which items should be displayed, from left to right. For example, if the contents of the array are {2,0,1}, the control displays item 2, item 0, and item 1, from left to right.