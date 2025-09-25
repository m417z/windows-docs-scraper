# ComboBox_GetItemData macro

## Syntax

```cpp
LRESULT ComboBox_GetItemData(
   HWND hwndCtl,
   int  index
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The item data. For more information, see **CB_GETITEMDATA**.

## Description

Gets the application-defined value associated with the specified list item in a combo box. You can use this macro or send the [CB_GETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/cb-getitemdata) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item.