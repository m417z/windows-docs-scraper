# ListBox_GetSelCount macro

## Syntax

```cpp
int ListBox_GetSelCount(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The number of selected items. If the list box is a single-selection list box, the return value is LB_ERR.

## Description

Gets the count of selected items in a multiple-selection list box. You can use this macro or send the [LB_GETSELCOUNT](https://learn.microsoft.com/windows/desktop/Controls/lb-getselcount) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [LB_GETSELCOUNT](https://learn.microsoft.com/windows/desktop/Controls/lb-getselcount).