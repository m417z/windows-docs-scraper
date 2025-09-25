# ListBox_GetItemHeight macro

## Syntax

```cpp
int ListBox_GetItemHeight(
   HWND hwndCtl,
   int  index
);
```

## Return value

Type: **int**

The height, in pixels, of the item or items, or LB_ERR if an error occurs.

## Description

Retrieves the height of items in a list box. If the list box has the [LBS_OWNERDRAWVARIABLE](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles) style, this macro gets the height of the specified item; otherwise, it gets the height of all items. You can use this macro or send the [LB_GETITEMHEIGHT](https://learn.microsoft.com/windows/desktop/Controls/lb-getitemheight) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item. If the list box does not have the [LBS_OWNERDRAWVARIABLE](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles) style, set this parameter to zero.

## Remarks

For more information, see [LB_GETITEMHEIGHT](https://learn.microsoft.com/windows/desktop/Controls/lb-getitemheight).