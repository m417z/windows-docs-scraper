# ListBox_InsertString macro

## Syntax

```cpp
int ListBox_InsertString(
   HWND   hwndCtl,
   int    index,
   LPCSTR lpsz
);
```

## Return value

Type: **int**

The return value is the zero-based index of the string in the list box. If an error occurs, the return value is LB_ERR. If there is insufficient space to store the new string, the return value is LB_ERRSPACE.

## Description

Adds a string to a list box at the specified location. You can use this macro or send the [LB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-insertstring) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index at which to insert the string, or –1 to add it to the end of the list.

### `lpsz`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The string to add.

## Remarks

For more information, see [LB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-insertstring).