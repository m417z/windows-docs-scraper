# ListView_SetHotCursor macro

## Syntax

```cpp
HCURSOR ListView_SetHotCursor(
   HWND    hwnd,
   HCURSOR hcur
);
```

## Return value

Type: **[HCURSOR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns an HCURSOR value that is the cursor that was previously used when the pointer was over an item.

## Description

Sets the HCURSOR that the list-view control uses when the pointer is over an item while hot tracking is enabled. You can use this macro or send the [LVM_SETHOTCURSOR](https://learn.microsoft.com/windows/desktop/Controls/lvm-sethotcursor) message explicitly. To check whether hot tracking is enabled, call [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa).

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `hcur`

Type: **[HCURSOR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the cursor to be set.

## Remarks

A list-view control uses hot tracking and hover selection when the [LVS_EX_TRACKSELECT](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles) style is set.