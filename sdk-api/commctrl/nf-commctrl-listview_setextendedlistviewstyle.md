# ListView_SetExtendedListViewStyle macro

## Syntax

```cpp
void ListView_SetExtendedListViewStyle(
   HWND  hwndLV,
   DWORD dw
);
```

## Description

Sets extended styles for list-view controls. You can use this macro or send the [LVM_SETEXTENDEDLISTVIEWSTYLE](https://learn.microsoft.com/windows/desktop/Controls/lvm-setextendedlistviewstyle) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control that will receive the style change.

### `dw`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A **DWORD** value that specifies the extended list-view control style. This parameter can be a combination of [Extended List-View Styles](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles).

## Remarks

For backward compatibility reasons, the **ListView_SetExtendedListViewStyle** macro has not been updated to use
*dwExMask*. To use the *dwExMask* value, use the [ListView_SetExtendedListViewStyleEx](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setextendedlistviewstyleex) macro.

When you use this macro to set the [LVS_EX_CHECKBOXES](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles) style, any previously set state image index will be discarded. All check boxes will be initialized to the unchecked state. The state image index is contained in bits 12 through 15 of the
**state** member of the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure.