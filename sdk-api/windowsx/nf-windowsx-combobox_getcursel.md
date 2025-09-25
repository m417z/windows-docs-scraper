# ComboBox_GetCurSel macro

## Syntax

```cpp
int ComboBox_GetCurSel(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The zero-based index of the selected item. If there is no selection, the return value is CB_ERR.

## Description

Gets the index of the currently selected item in a combo box. You can use this macro or send the [CB_GETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/cb-getcursel) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.