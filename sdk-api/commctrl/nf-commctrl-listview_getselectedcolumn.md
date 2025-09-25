# ListView_GetSelectedColumn macro

## Syntax

```cpp
UINT ListView_GetSelectedColumn(
   HWND hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **UINT** that specifies the selected column.

## Description

Gets an integer that specifies the selected column. You can use this macro or send the [LVM_GETSELECTEDCOLUMN](https://learn.microsoft.com/windows/desktop/Controls/lvm-getselectedcolumn) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## Remarks

To use **ListView_GetSelectedColumn**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).