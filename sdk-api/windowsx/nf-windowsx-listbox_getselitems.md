# ListBox_GetSelItems macro

## Syntax

```cpp
int ListBox_GetSelItems(
   HWND hwndCtl,
   int  cItems,
   int  *lpItems
);
```

## Return value

Type: **int**

The number of items placed in the buffer. If the list box is a single-selection list box, the return value is LB_ERR.

## Description

Gets the indexes of selected items in a multiple-selection list box. You can use this macro or send the [LB_GETSELITEMS](https://learn.microsoft.com/windows/desktop/Controls/lb-getselitems) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `cItems`

Type: **int**

The maximum number of selected items whose item numbers are to be placed in the buffer.

### `lpItems`

Type: **int***

A pointer to a buffer large enough for the number of integers specified by *cItems*.