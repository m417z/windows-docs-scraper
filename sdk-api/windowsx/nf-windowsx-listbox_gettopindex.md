# ListBox_GetTopIndex macro

## Syntax

```cpp
int ListBox_GetTopIndex(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The zero-based index of the first visible item.

## Description

Gets the index of the first visible item in a list box. You can use this macro or send the [LB_GETTOPINDEX](https://learn.microsoft.com/windows/desktop/controls/lb-gettopindex) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.