# ListBox_GetCurSel macro

## Syntax

```cpp
int ListBox_GetCurSel(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The zero-based index of the selected item. If there is no selection, the return value is LB_ERR.

## Description

Gets the index of the currently selected item in a single-selection list box. You can use this macro or send the [LB_GETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/lb-getcursel) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [LB_GETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/lb-getcursel).