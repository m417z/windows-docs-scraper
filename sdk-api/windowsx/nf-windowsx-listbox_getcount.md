# ListBox_GetCount macro

## Syntax

```cpp
int ListBox_GetCount(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The number of items.

## Description

Gets the number of items in a list box. You can use this macro or send the [LB_GETCOUNT](https://learn.microsoft.com/windows/desktop/Controls/lb-getcount) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.