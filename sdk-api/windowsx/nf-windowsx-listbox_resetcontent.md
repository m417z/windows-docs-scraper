# ListBox_ResetContent macro

## Syntax

```cpp
BOOL ListBox_ResetContent(
   HWND hwndCtl
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is not meaningful.

## Description

Removes all items from a list box. You can use this macro or send the [LB_RESETCONTENT](https://learn.microsoft.com/windows/desktop/Controls/lb-resetcontent) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.