# ListView_SetSelectedColumn macro

## Syntax

```cpp
void ListView_SetSelectedColumn(
   HWND hwnd,
   int  iCol
);
```

## Description

Sets the index of the selected column. You can use this macro or send the [LVM_SETSELECTEDCOLUMN](https://learn.microsoft.com/windows/desktop/Controls/lvm-setselectedcolumn) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iCol`

Type: **int**

**int**

## Remarks

To use **ListView_SetSelectedColumn**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).