# ListBox_SelItemRange macro

## Syntax

```cpp
int ListBox_SelItemRange(
   HWND hwndCtl,
   BOOL fSelect,
   int  first,
   int  last
);
```

## Return value

Type: **int**

If an error occurs, the return value is LB_ERR.

## Description

Selects or deselects one or more consecutive items in a multiple-selection list box. You can use this macro or send the [LB_SELITEMRANGE](https://learn.microsoft.com/windows/desktop/Controls/lb-selitemrange) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `fSelect`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to select the range of items, or **FALSE** to deselect it.

### `first`

Type: **int**

The zero-based index of the first item to select.

### `last`

Type: **int**

The zero-based index of the last item to select.