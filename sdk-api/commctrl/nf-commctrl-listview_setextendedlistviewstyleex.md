# ListView_SetExtendedListViewStyleEx macro

## Syntax

```cpp
void ListView_SetExtendedListViewStyleEx(
   HWND  hwndLV,
   DWORD dwMask,
   DWORD dw
);
```

## Description

Sets extended styles for list-view controls using the style mask. You can use this macro or send the [LVM_SETEXTENDEDLISTVIEWSTYLE](https://learn.microsoft.com/windows/desktop/Controls/lvm-setextendedlistviewstyle) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control that will receive the style change.

### `dwMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A **DWORD** value that specifies which styles in *dw* are to be affected. This parameter can be a combination of [Extended List-View Styles](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles). Only the extended styles in *dwMask* will be changed. All other styles will be maintained as they are. If this parameter is zero, all of the styles in *dw* will be affected.

### `dw`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A **DWORD** value that specifies the extended list-view control styles to set. This parameter can be a combination of [Extended List-View Styles](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles). Styles that are not set, but that are specified in *dwMask*, are removed.

## Remarks

When you use this macro to set the [LVS_EX_CHECKBOXES](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles) style, any previously set state image index will be discarded. All check boxes will be initialized to the unchecked state. The state image index is contained in bits 12 through 15 of the **state** member of the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure.