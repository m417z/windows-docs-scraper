# ListView_GetHeader macro

## Syntax

```cpp
HWND ListView_GetHeader(
   HWND hwnd
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the header control.

## Description

Gets the handle to the header control used by a list-view control. You can use this macro or send the [LVM_GETHEADER](https://learn.microsoft.com/windows/desktop/Controls/lvm-getheader) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.