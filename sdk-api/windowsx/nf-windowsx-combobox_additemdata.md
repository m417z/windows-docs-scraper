# ComboBox_AddItemData macro

## Syntax

```cpp
int ComboBox_AddItemData(
   HWND   hwndCtl,
   LPARAM data
);
```

## Return value

Type: **int**

The return value is the zero-based index of the item in the list. If an error occurs, the return value is CB_ERR. If there is insufficient space to store the new string, the return value is CB_ERRSPACE.

## Description

Adds item data to the list in a combo box at the specified location. You can use this macro or send the [CB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-addstring) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `data`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the item data to add.

## Remarks

Use this macro for a list in a combo box with an owner-drawn style but without the [CBS_HASSTRINGS](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles) style. For more information, see [CB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-addstring).