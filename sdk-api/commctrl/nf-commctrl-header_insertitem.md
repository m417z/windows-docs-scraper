# Header_InsertItem macro

## Syntax

```cpp
int Header_InsertItem(
         HWND     hwndHD,
         int      i,
   const LPHDITEM phdi
);
```

## Return value

Type: **int**

Returns the index of the new item if successful, or -1 otherwise.

## Description

Inserts a new item into a header control. You can use this macro or send the [HDM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/hdm-insertitem) message explicitly.

## Parameters

### `hwndHD`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

### `i`

Type: **int**

The index of the item after which the new item is to be inserted. The new item is inserted at the end of the header control if *i* is greater than or equal to the number of items in the control. If *i* is zero, the new item is inserted at the beginning of the header control.

### `phdi`

Type: **const LPHDITEM**

A pointer to an [HDITEM](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-hditema) structure that contains information about the new item.

## Remarks

The **Header_InsertItem** macro is defined as follows:

``` syntax
#define Header_InsertItem(hwndHD, i, phdi) \

    (int)SendMessage((hwndHD), HDM_INSERTITEM, (WPARAM)(int)(i), \

    (LPARAM)(const LPHDITEM)(phdi))
```