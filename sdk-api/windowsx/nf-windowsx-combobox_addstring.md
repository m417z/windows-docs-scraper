# ComboBox_AddString macro

## Syntax

```cpp
int ComboBox_AddString(
   HWND    hwndCtl,
   LPCTSTR lpsz
);
```

## Return value

Type: **int**

The return value is the zero-based index of the string in the list. If an error occurs, the return value is CB_ERR. If there is insufficient space to store the new string, the return value is CB_ERRSPACE.

## Description

Adds a string to a list in a combo box. If the combo box does not have the [CBS_SORT](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles) style, the string is added to the end of the list. Otherwise, the string is inserted into the list and the list is sorted. You can use this macro or send the [CB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-addstring) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `lpsz`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The string to add.

## Remarks

For more information, see [CB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-addstring).