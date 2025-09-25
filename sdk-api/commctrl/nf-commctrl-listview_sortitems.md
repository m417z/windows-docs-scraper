# ListView_SortItems macro

## Syntax

```cpp
BOOL ListView_SortItems(
   HWND         hwndLV,
   PFNLVCOMPARE _pfnCompare,
   LPARAM       _lPrm
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Uses an application-defined comparison function to sort the items of a list-view control. The index of each item changes to reflect the new sequence. You can use this macro or send the [LVM_SORTITEMS](https://learn.microsoft.com/windows/desktop/Controls/lvm-sortitems) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `_pfnCompare`

Type: **PFNLVCOMPARE**

A pointer to the application-defined comparison function. The comparison function is called during the sort operation each time the relative order of two list items needs to be compared.

### `_lPrm`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The application-defined value that is passed to the comparison function.

## Remarks

The comparison function has the following form.

``` syntax
int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM _lPrm);
```

The *lParam1* parameter is the value associated with the first item being compared; and the *lParam2* parameter is the value associated with the second item. These are the values that were specified in the **lParam** member of the items' [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure when they were inserted into the list. The *_lPrm* parameter is the same value passed to the [LVM_SORTITEMS](https://learn.microsoft.com/windows/desktop/Controls/lvm-sortitems) message.

The comparison function must return a negative value if the first item should precede the second, a positive value if the first item should follow the second, or zero if the two items are equivalent.

**Note** During the sorting process, the list-view contents are unstable. If the callback function sends any messages to the list-view control, the results are unpredictable.