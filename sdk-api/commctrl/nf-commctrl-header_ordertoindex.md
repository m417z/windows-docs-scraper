# Header_OrderToIndex macro

## Syntax

```cpp
int Header_OrderToIndex(
   HWND hwnd,
   int  i
);
```

## Return value

Type: **int**

Returns an **int** that specifies the index of the item. If *i* is invalid (negative or too large), the return equals *i*.

## Description

Retrieves an index value for an item based on its order in the header control. You can use this macro or send the [HDM_ORDERTOINDEX](https://learn.microsoft.com/windows/desktop/controls/hdm-ordertoindex) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.

### `i`

Type: **int**

The order that the item appears within the header control, from left to right. The index value of the item in the far left column would be 0, the next item to the right would be 1, and so on.