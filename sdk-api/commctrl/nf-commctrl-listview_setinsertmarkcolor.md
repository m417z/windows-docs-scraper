# ListView_SetInsertMarkColor macro

## Syntax

```cpp
COLORREF ListView_SetInsertMarkColor(
   HWND     hwnd,
   COLORREF color
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **COLORREF** structure set to the previous color.

## Description

Sets the color of the insertion point. You can use this macro or send the [LVM_SETINSERTMARKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/lvm-setinsertmarkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `color`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**COLORREF**

## Remarks

To use **ListView_SetInsertMarkColor**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).