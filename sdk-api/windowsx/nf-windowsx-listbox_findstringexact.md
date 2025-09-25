# ListBox_FindStringExact macro

## Syntax

```cpp
int ListBox_FindStringExact(
   HWND    hwndCtl,
   int     indexStart,
   LPCTSTR lpszFind
);
```

## Return value

Type: **int**

The index of the matching item, or LB_ERR if the search was unsuccessful.

## Description

Finds the first list box string that exactly matches the specified string, except that the search is not case sensitive. You can use this macro or send the [LB_FINDSTRINGEXACT](https://learn.microsoft.com/windows/desktop/Controls/lb-findstringexact) message explicitly.

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

For more information, see [LB_FINDSTRINGEXACT](https://learn.microsoft.com/windows/desktop/Controls/lb-findstringexact).

## See also

[ListBox_FindString](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-listbox_findstring)