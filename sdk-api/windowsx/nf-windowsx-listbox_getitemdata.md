# ListBox_GetItemData macro

## Syntax

```cpp
LRESULT ListBox_GetItemData(
   HWND hwndCtl,
   int  index
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The item data. For more information, see **LB_GETITEMDATA**.

## Description

Gets the application-defined value associated with the specified list box item. You can use this macro or send the [LB_GETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/lb-getitemdata) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item.