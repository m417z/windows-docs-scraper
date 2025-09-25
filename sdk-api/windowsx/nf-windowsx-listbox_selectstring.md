# ListBox_SelectString macro

## Syntax

```cpp
int ListBox_SelectString(
   HWND    hwndCtl,
   int     indexStart,
   LPCTSTR lpszFind
);
```

## Return value

Type: **int**

If the search is successful, the return value is the index of the selected item. If the search is unsuccessful, the return value is LB_ERR and the current selection is not changed.

## Description

Searches a list box for an item that begins with the characters in a specified string. If a matching item is found, the item is selected. You can use this macro or send the [LB_SELECTSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-selectstring) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `indexStart`

Type: **int**

The zero-based index of the item before the first item to be searched. When the search reaches the bottom of the list box, it continues searching from the top of the list box back to the item specified by the *indexStart* parameter. If *indexStart* is –1, the entire list box is searched from the beginning.

### `lpszFind`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The string to find.

## Remarks

For more information, see [LB_SELECTSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-selectstring).