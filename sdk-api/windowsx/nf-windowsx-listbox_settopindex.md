# ListBox_SetTopIndex macro

## Syntax

```cpp
int ListBox_SetTopIndex(
   HWND hwndCtl,
   int  indexTop
);
```

## Return value

Type: **int**

If an error occurs, the return value is LB_ERR.

## Description

Ensures that the specified item in a list box is visible. You can use this macro or send the [LB_SETTOPINDEX](https://learn.microsoft.com/windows/desktop/controls/lb-settopindex) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `indexTop`

Type: **int**

The zero-based index of the item to put at the top of the visible part of the list.

## Remarks

The list box contents are scrolled so that either the specified item appears at the top of the list box or the maximum scroll range has been reached.