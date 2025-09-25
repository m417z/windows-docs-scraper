# ComboBox_GetCount macro

## Syntax

```cpp
int ComboBox_GetCount(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The number of items.

## Description

Gets the number of items in the list box of a combo box. You can use this macro or send the [CB_GETCOUNT](https://learn.microsoft.com/windows/desktop/Controls/cb-getcount) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.