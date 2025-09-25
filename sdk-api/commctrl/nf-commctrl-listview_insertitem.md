# ListView_InsertItem macro

## Syntax

```cpp
int ListView_InsertItem(
         HWND     hwnd,
   const LPLVITEM pitem
);
```

## Return value

Type: **int**

Returns the index of the new item if successful, or -1 otherwise.

## Description

Inserts a new item in a list-view control. You can use this macro or send the [LVM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `pitem`

Type: **const LPLVITEM**

A pointer to an [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure that specifies the attributes of the list-view item. Use the **iItem** member to specify the zero-based index at which the new item should be inserted. If this value is greater than the number of items currently contained by the listview control, the new item will be appended to the end of the list and assigned the correct index. Examine the macro's return value to determine the actual index assigned to the item.

## Remarks

You cannot use **ListView_InsertItem** or [LVM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertitem) to insert subitems. The **iSubItem** member of the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure must be zero. See [LVM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitem) for information on setting subitems.

If a list-view control has the [LVS_EX_CHECKBOXES](https://learn.microsoft.com/windows/desktop/Controls/extended-list-view-styles) style set, any value placed in bits 12 through 15 of the **state** member of the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure will be ignored. When an item is added with this style set, it will always be set to the unchecked state.

If a list-view control has either the [LVS_SORTASCENDING](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) or [LVS_SORTDESCENDING](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) window style, an [LVM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertitem) message will fail if you try to insert an item that has LPSTR_TEXTCALLBACK as the **pszText** member of its [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure.

The **ListView_InsertItem** macro will insert the new item in the proper position in the sort order if the following conditions hold:

* You are using one of the LVS_SORTXXX styles.
* You are not using the LVS_OWNERDRAW style.
* The
  **pszText** member of the structure pointed to by *pitem* is not set to LPSTR_TEXTCALLBACK.