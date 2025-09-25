# ComboBox_SelectItemData macro

## Syntax

```cpp
int ComboBox_SelectItemData(
   HWND   hwndCtl,
   int    indexStart,
   LPARAM data
);
```

## Return value

Type: **int**

If the search is successful, the return value is the index of the selected item. If the search is unsuccessful, the return value is CB_ERR and the current selection is not changed.

## Description

Searches a list in a combo box for an item that has the specified item data. If a matching item is found, the item is selected. You can use this macro or send the [CB_SELECTSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-selectstring) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `indexStart`

Type: **int**

The zero-based index of the item before the first item to be searched. When the search reaches the bottom of the list, it continues searching from the top of the list back to the item specified by the *indexStart* parameter. If *indexStart* is –1, the entire list is searched from the beginning.

### `data`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The item data to find.

## Remarks

For more information, see [CB_SELECTSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-selectstring).