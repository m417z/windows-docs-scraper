# ListBox_SetCaretIndex macro

## Syntax

```cpp
int ListBox_SetCaretIndex(
   HWND hwndCtl,
   int  index
);
```

## Return value

Type: **int**

If an error occurs, the return value is LB_ERR.

## Description

Sets the focus rectangle to the item at the specified index in a multiple-selection list box. If the item is not visible, it is scrolled into view. You can use this macro or send the [LB_SETCARETINDEX](https://learn.microsoft.com/windows/desktop/controls/lb-setcaretindex) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

 the zero-based index of the list box item that is to receive the focus rectangle.

## Remarks

The contents of the list box are scrolled till the item is fully visible.

For more information, see [LB_SETCARETINDEX](https://learn.microsoft.com/windows/desktop/controls/lb-setcaretindex).