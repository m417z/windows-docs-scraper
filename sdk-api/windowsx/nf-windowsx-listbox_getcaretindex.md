# ListBox_GetCaretIndex macro

## Syntax

```cpp
int ListBox_GetCaretIndex(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The zero-based index of the focused item, or 0 if no item has the focus.

## Description

Retrieves the index of the list box item that has the focus rectangle in a multiple-selection list box. The item may or may not be selected. You can use this macro or send the [LB_GETCARETINDEX](https://learn.microsoft.com/windows/desktop/controls/lb-getcaretindex) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

The contents of the list box are scrolled till the item is fully visible.

For more information, see [LB_GETCARETINDEX](https://learn.microsoft.com/windows/desktop/controls/lb-getcaretindex).