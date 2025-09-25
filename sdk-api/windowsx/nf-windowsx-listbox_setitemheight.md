# ListBox_SetItemHeight macro

## Syntax

```cpp
int ListBox_SetItemHeight(
   HWND   hwndCtl,
   int    index,
   LPARAM cy
);
```

## Return value

Type: **int**

If the index or height is invalid, the return value is LB_ERR.

## Description

Sets the height of items in a list box. If the list box has the [LBS_OWNERDRAWVARIABLE](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles) style, this macro sets the height of the specified item; otherwise, it sets the height of all items. You can use this macro or send the [LB_SETITEMHEIGHT](https://learn.microsoft.com/windows/desktop/Controls/lb-setitemheight) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item. If the list box does not have the [LBS_OWNERDRAWVARIABLE](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles) style, set this parameter to zero.

### `cy`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The height of the item or items, in pixels.

## Remarks

For more information, see [LB_SETITEMHEIGHT](https://learn.microsoft.com/windows/desktop/Controls/lb-setitemheight).