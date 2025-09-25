# TVSORTCB structure

## Description

Contains information used to sort child items in a tree-view control. This structure is used with the [TVM_SORTCHILDRENCB](https://learn.microsoft.com/windows/desktop/Controls/tvm-sortchildrencb) message. This structure is identical to the
**TV_SORTCB** structure, but it has been renamed to follow current naming conventions.

## Members

### `hParent`

Type: **HTREEITEM**

Handle to the parent item.

### `lpfnCompare`

Type: **PFNTVCOMPARE**

Address of an application-defined callback function, which is called during a sort operation each time the relative order of two list items needs to be compared.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined value that gets passed as the
*lParamSort* argument in the callback function specified in
**lpfnCompare**.

## Remarks

The callback function specified by **lpfnCompare** has the following form:

``` syntax

int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

```

The callback function must return a negative value if the first item should precede the second, a positive value if the first item should follow the second, or zero if the two items are equivalent.

The *lParam1* and *lParam2* parameters correspond to the lParam member of the [TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema) structure for the two items being compared. The *lParamSort* parameter corresponds to the **lParam** member of this structure.