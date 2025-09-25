# ListBox_InsertItemData macro

## Syntax

```cpp
int ListBox_InsertItemData(
   HWND   hwndCtl,
   int    index,
   LPARAM data
);
```

## Return value

Type: **int**

The return value is the zero-based index of the item in the list box. If an error occurs, the return value is LB_ERR. If there is insufficient space to store the new string, the return value is LB_ERRSPACE.

## Description

Inserts item data to a list box at the specified location. You can use this macro or send the [LB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-insertstring) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index in the list at which to insert the item data, or –1 to add it to the end of the list.

### `data`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the item data to insert.

## Remarks

Use this macro for a list box with an owner-drawn style but without the [LBS_HASSTRINGS](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles) style. For more information, see [LB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-insertstring).