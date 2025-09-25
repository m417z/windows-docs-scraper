# Header_GetItem macro

## Syntax

```cpp
BOOL Header_GetItem(
   HWND     hwndHD,
   int      i,
   LPHDITEM phdi
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets information about an item in a header control. You can use this macro or send the [HDM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/hdm-getitem) message explicitly.

## Parameters

### `hwndHD`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

### `i`

Type: **int**

The index of the item for which information is to be retrieved.

### `phdi`

Type: **LPHDITEM**

A pointer to an [HDITEM](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-hditema) structure. When the message is sent, the **mask** member indicates the type of information being requested. When the message returns, the other members receive the requested information. If the
**mask** member specifies zero, the message returns **TRUE** but copies no information to the structure.

## Remarks

If the HDI_TEXT flag is set in the
**mask** member of the [HDITEM](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-hditema) structure, the control may change the
**pszText** member of the structure to point to the new text instead of filling the buffer with the requested text. Applications should not assume that the text will always be placed in the requested buffer.

The **Header_GetItem** macro is defined as follows:

``` syntax
#define Header_GetItem(hwndHD, i, phdi)      \

    (BOOL)SendMessage((hwndHD), HDM_GETITEM,   \

    (WPARAM)(int)(i), (LPARAM)(LPHDITEM)(phdi))
```