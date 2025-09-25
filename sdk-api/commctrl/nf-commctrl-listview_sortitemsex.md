# ListView_SortItemsEx macro

## Syntax

```cpp
BOOL ListView_SortItemsEx(
   HWND         hwndLV,
   PFNLVCOMPARE _pfnCompare,
   LPARAM       _lPrm
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Uses an application-defined comparison function to sort the items of a list-view control. The index of each item changes to reflect the new sequence. You can use this macro or send the [LVM_SORTITEMSEX](https://learn.microsoft.com/windows/desktop/Controls/lvm-sortitemsex) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `_pfnCompare`

Type: **PFNLVCOMPARE**

A pointer to an application-defined comparison function. It is called during the sort operation each time the relative order of two list items needs to be compared.

### `_lPrm`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The application-defined value that is passed to the comparison function.

## Remarks

The comparison function has the following form.

``` syntax
int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM _lPrm);
```

where *lParam1* is the index of the first item and *lParam2* the index of the second. The **ListView_SortItemsEx**'s *_lPrm* parameter is passed to the callback function as its third parameter.

The comparison function must return a negative value if the first item should precede the second, a positive value if the first item should follow the second, or zero if the two items are equivalent.

You can send an [LVM_GETITEMTEXT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitemtext) message to retrieve further information on an item, if needed.

This macro is similar to [ListView_SortItems](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_sortitems), except for the type of information passed to the comparison function. With **ListView_SortItemsEx**, the item's index is passed instead of its *lparam* value.

**Note** During the sorting process, the list-view contents are unstable. If the callback function sends any messages to the list-view control aside from [LVM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitem) ([ListView_GetItem](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_getitem)), the results are unpredictable.