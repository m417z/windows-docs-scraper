# ListBox_GetSel macro

## Syntax

```cpp
DWORD ListBox_GetSel(
   HWND hwndCtl,
   int  index
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the item is selected, the return value is greater than zero; otherwise, it is zero. If an error occurs, the return value is LB_ERR.

## Description

Gets the selection state of an item. You can use this macro or send the [LB_GETSEL](https://learn.microsoft.com/windows/desktop/Controls/lb-getsel) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item.

## Remarks

For more information, see [LB_GETSEL](https://learn.microsoft.com/windows/desktop/Controls/lb-getsel)