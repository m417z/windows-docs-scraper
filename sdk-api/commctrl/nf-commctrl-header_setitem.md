# Header_SetItem macro

## Syntax

```cpp
BOOL Header_SetItem(
   HWND     hwndHD,
   int      i,
   LPHDITEM phdi
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Sets the attributes of the specified item in a header control. You can use this macro or send the [HDM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/hdm-setitem) message explicitly.

## Parameters

### `hwndHD`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.

### `i`

Type: **int**

The current index of the item whose attributes are to be changed.

### `phdi`

Type: **LPHDITEM**

A pointer to an [HDITEM](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-hditema) structure that contains item information. When this message is sent, the
**mask** member of the structure must be set to indicate which attributes are being set.

## Remarks

The [HDITEM](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-hditema) structure that supports this macro supports item order and image list information. By using these members, you can control the order in which items are displayed and specify images to appear with items.