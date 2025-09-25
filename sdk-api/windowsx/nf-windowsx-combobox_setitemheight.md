# ComboBox_SetItemHeight macro

## Syntax

```cpp
int ComboBox_SetItemHeight(
   HWND hwndCtl,
   int  index,
   int  cyItem
);
```

## Return value

Type: **int**

If the index or height is invalid, the return value is CB_ERR.

## Description

Sets the height of list items or the selection field in a combo box. You can use this macro or send the [CB_SETITEMHEIGHT](https://learn.microsoft.com/windows/desktop/Controls/cb-setitemheight) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The component of the combo box for which to set the height. This parameter must be –1 to set the height of the selection field. It must be zero to set the height of list items, unless the combo box has the [CBS_OWNERDRAWVARIABLE](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles) style. In that case, the *index* parameter is the zero-based index of a specific list item.

### `cyItem`

Type: **int**

The height in pixels.

## Remarks

For more information, see [CB_SETITEMHEIGHT](https://learn.microsoft.com/windows/desktop/Controls/cb-setitemheight).