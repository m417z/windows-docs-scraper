# ListView_GetView macro

## Syntax

```cpp
DWORD ListView_GetView(
   HWND hwnd
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **DWORD** that specifies the current view.

## Description

Gets the current view of a list-view control. You can use this macro or send the [LVM_GETVIEW](https://learn.microsoft.com/windows/desktop/Controls/lvm-getview) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## Remarks

To use **ListView_GetView**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).