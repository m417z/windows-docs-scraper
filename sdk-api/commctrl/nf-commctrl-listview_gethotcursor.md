# ListView_GetHotCursor macro

## Syntax

```cpp
HCURSOR ListView_GetHotCursor(
   HWND hwnd
);
```

## Return value

Type: **[HCURSOR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns an HCURSOR value that is the handle to the cursor that the list-view control uses when hot tracking is enabled.

## Description

Gets the HCURSOR used when the pointer is over an item while hot tracking is enabled. You can use this macro or send the [LVM_GETHOTCURSOR](https://learn.microsoft.com/windows/desktop/Controls/lvm-gethotcursor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

## Remarks

A list-view control uses hot tracking and hover selection when the [LVS_EX_TRACKSELECT](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles) style is set.