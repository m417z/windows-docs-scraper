# ListBox_AddString macro

## Syntax

```cpp
int ListBox_AddString(
   HWND   hwndCtl,
   LPCSTR lpsz
);
```

## Return value

Type: **int**

The return value is the zero-based index of the string in the list box. If an error occurs, the return value is LB_ERR. If there is insufficient space to store the new string, the return value is LB_ERRSPACE.

## Description

Adds a string to a list box. If the list box does not have the [LBS_SORT](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles) style, the string is added to the end of the list. Otherwise, the string is inserted into the list and the list is sorted. You can use this macro or send the [LB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-addstring) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `lpsz`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The string to add.

## Remarks

For more information, see [LB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-addstring).