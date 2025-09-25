# Header_GetItemCount macro

## Syntax

```cpp
int Header_GetItemCount(
   HWND hwndHD
);
```

## Return value

Type: **int**

Returns the number of items if successful, or -1 otherwise.

## Description

Gets a count of the items in a header control. You can use this macro or send the [HDM_GETITEMCOUNT](https://learn.microsoft.com/windows/desktop/Controls/hdm-getitemcount) message explicitly.

## Parameters

### `hwndHD`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

## Remarks

The **Header_GetItemCount** macro is defined as follows.

``` syntax
#define Header_GetItemCount(hwndHD)   \

       (int)SendMessage((hwndHD), HDM_GETITEMCOUNT, 0, 0L)
```