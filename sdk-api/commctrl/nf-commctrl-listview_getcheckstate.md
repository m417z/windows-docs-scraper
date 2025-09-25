# ListView_GetCheckState macro

## Syntax

```cpp
BOOL ListView_GetCheckState(
   HWND hwndLV,
   UINT i
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if the given item is selected, or zero otherwise. If this macro is applied to a list-view control that does not have check boxes enabled, the return value is not reliable.

## Description

Determines if an item in a list-view control is selected. This should be used only for list-view controls that have the [LVS_EX_CHECKBOXES](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles) style.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `i`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the item for which to retrieve the check state.