# Header_DeleteItem macro

## Syntax

```cpp
BOOL Header_DeleteItem(
   HWND hwndHD,
   int  i
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Deletes an item from a header control. You can use this macro or send the [HDM_DELETEITEM](https://learn.microsoft.com/windows/desktop/Controls/hdm-deleteitem) message explicitly.

## Parameters

### `hwndHD`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

### `i`

Type: **int**

An index of the item to delete.

## Remarks

The **Header_DeleteItem** macro is defined as follows.

``` syntax
#define Header_DeleteItem(hwndHD, i)     \

      (BOOL)SendMessage((hwndHD), HDM_DELETEITEM, (WPARAM)(int)(i), 0L)
```