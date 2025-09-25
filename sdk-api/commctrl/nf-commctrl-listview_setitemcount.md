# ListView_SetItemCount macro

## Syntax

```cpp
void ListView_SetItemCount(
   HWND hwndLV,
   int  cItems
);
```

## Description

Causes the list-view control to allocate memory for the specified number of items. You can use this macro or send the [LVM_SETITEMCOUNT](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitemcount) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `cItems`

Type: **int**

The number of items for which the list-view control should allocate memory.

## Remarks

If the list-view control was created without the [LVS_OWNERDATA](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style, this macro causes the control to allocate its internal data structures for the specified number of items. This prevents the control from having to allocate the data structures every time an item is added.

If the list-view control was created with the [LVS_OWNERDATA](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style (a [virtual list view](https://learn.microsoft.com/windows/desktop/Controls/list-view-controls-overview)), the [ListView_SetItemCountEx](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setitemcountex) macro should be used.