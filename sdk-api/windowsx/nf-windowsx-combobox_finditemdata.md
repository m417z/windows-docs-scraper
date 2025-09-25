# ComboBox_FindItemData macro

## Syntax

```cpp
int ComboBox_FindItemData(
   HWND   hwndCtl,
   int    indexStart,
   LPARAM data
);
```

## Return value

Type: **int**

The index of the matching item, or CB_ERR if the search was unsuccessful.

## Description

Finds the first item in a combo box list that has the specified item data. You can use this macro or send the [CB_FINDSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-findstring) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `indexStart`

Type: **int**

The zero-based index of the item before the first item to be searched. When the search reaches the bottom of the list, it continues searching from the top of the list back to the item specified by the *indexStart* parameter. If *indexStart* is –1, the entire list is searched from the beginning.

### `data`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The data to find.

## Remarks

For more information, see [CB_FINDSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-findstring).