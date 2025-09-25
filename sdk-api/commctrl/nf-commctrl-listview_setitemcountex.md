# ListView_SetItemCountEx macro

## Syntax

```cpp
void ListView_SetItemCountEx(
   HWND  hwndLV,
   int   cItems,
   DWORD dwFlags
);
```

## Description

Sets the virtual number of items in a [virtual list view](https://learn.microsoft.com/windows/desktop/Controls/list-view-controls-overview). You can use this macro or send the [LVM_SETITEMCOUNT](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitemcount) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a virtual list-view control.

### `cItems`

Type: **int**

The number of items that the list-view control will contain.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Values that specify the behavior of the list-view control after resetting the item count. This value can be a combination of the following:

| Value | Meaning |
| --- | --- |
| **LVSICF_NOINVALIDATEALL** | The list-view control will not repaint unless affected items are currently in view. |
| **LVSICF_NOSCROLL** | The list-view control will not change the scroll position when the item count changes. |

## Remarks

This macro is intended only for list-view controls that use the [LVS_OWNERDATA](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) and [LVS_REPORT](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) or [LVS_LIST](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) styles.

If the list-view control was created with the [LVS_OWNERDATA](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style, this macro sets the virtual number of items that the control contains.

If the list-view control was created without the [LVS_OWNERDATA](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style, the [ListView_SetItemCount](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setitemcount) macro should be used.