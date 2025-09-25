# ComboBox_GetLBTextLen macro

## Syntax

```cpp
int ComboBox_GetLBTextLen(
   HWND hwndCtl,
   int  index
);
```

## Return value

Type: **int**

The count of characters in the string.

## Description

Gets the length of a string in the list in a combo box. You can use this macro or send the [CB_GETLBTEXTLEN](https://learn.microsoft.com/windows/desktop/Controls/cb-getlbtextlen) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item.

## Remarks

For more information, see [CB_GETLBTEXTLEN](https://learn.microsoft.com/windows/desktop/Controls/cb-getlbtextlen).