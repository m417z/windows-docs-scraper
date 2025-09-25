# ListBox_GetItemRect macro

## Syntax

```cpp
int ListBox_GetItemRect(
   HWND hwndCtl,
   int  index,
   RECT *lprc
);
```

## Return value

Type: **int**

If an error occurs, the return value is LB_ERR.

## Description

Gets the dimensions of the rectangle that bounds a list box item as it is currently displayed in the list box. You can use this macro or send the [LB_GETITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/lb-getitemrect) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item in the list box.

### `lprc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the client coordinates for the item in the list box.