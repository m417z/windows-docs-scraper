# ComboBox_DeleteString macro

## Syntax

```cpp
int ComboBox_DeleteString(
   HWND hwndCtl,
   int  index
);
```

## Return value

Type: **int**

The return value is a count of the strings remaining in the list. The return value is CB_ERR if the *index* parameter specifies an index greater than the number of items in the list.

## Description

Deletes the item at the specified location in a list in a combo box. You can use this macro or send the [CB_DELETESTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-deletestring) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item to delete.

## Remarks

For more information, see [CB_DELETESTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-deletestring)