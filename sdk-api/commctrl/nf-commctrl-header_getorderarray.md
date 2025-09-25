# Header_GetOrderArray macro

## Syntax

```cpp
BOOL Header_GetOrderArray(
   HWND hwnd,
   int  iCount,
   int  *lpi
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, and the buffer at *lpiArray* receives the item number of each item in the header control in the order in which they appear from left to right. Returns zero otherwise.

## Description

Gets the current left-to-right order of items in a header control. You can use this macro or send the [HDM_GETORDERARRAY](https://learn.microsoft.com/windows/desktop/Controls/hdm-getorderarray) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.

### `iCount`

Type: **int**

The number of integer elements that
*lpiArray* can hold. This value must be equal to the number of items in the control (see [HDM_GETITEMCOUNT](https://learn.microsoft.com/windows/desktop/Controls/hdm-getitemcount)).

### `lpi`

Type: **int***

A pointer to an array of integers that receive the index values for items in the header.

## Remarks

The number of elements in *lpiArray* is specified in *iCount* and must be equal to the number of items in the control. For example, the following code fragment will reserve enough memory to hold the index values.

```

int iItems,

    *lpi;

// Get memory for buffer

if((iItems = SendMessage(hwnd, HDM_GETITEMCOUNT, 0,0))!=-1)

    if(!(lpiArray = calloc(iItems,sizeof(int))))

MessageBox(hwnd, "Out of memory.","Error", MB_OK);
```