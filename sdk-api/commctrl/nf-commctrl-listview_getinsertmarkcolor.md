# ListView_GetInsertMarkColor macro

## Syntax

```cpp
COLORREF ListView_GetInsertMarkColor(
   HWND hwnd
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **COLORREF** structure that contains the color of the insertion point.

## Description

Gets the color of the insertion point. You can use this macro or send the [LVM_GETINSERTMARKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/lvm-getinsertmarkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## Remarks

To use **ListView_GetInsertMarkColor**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).