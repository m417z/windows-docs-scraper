# ListBox_GetTextLen macro

## Syntax

```cpp
int ListBox_GetTextLen(
   HWND hwndCtl,
   int  index
);
```

## Return value

Type: **int**

The count of characters in the string.

## Description

Gets the length of a string in a list box. You can use this macro or send the [LB_GETTEXTLEN](https://learn.microsoft.com/windows/desktop/Controls/lb-gettextlen) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item.

## Remarks

For more information, see [LB_GETTEXTLEN](https://learn.microsoft.com/windows/desktop/Controls/lb-gettextlen).