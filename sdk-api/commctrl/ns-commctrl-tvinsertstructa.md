# TVINSERTSTRUCTA structure

## Description

Contains information used to add a new item to a tree-view control. This structure is used with the [TVM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-insertitem) message. The structure is identical to the **TV_INSERTSTRUCT** structure, but it has been renamed to follow current naming conventions.

## Members

### `hParent`

Type: **HTREEITEM**

Handle to the parent item. If this member is the TVI_ROOT value or **NULL**, the item is inserted at the root of the tree-view control.

### `hInsertAfter`

Type: **HTREEITEM**

Handle to the item after which the new item is to be inserted, or one of the following values:

| Value | Meaning |
| --- | --- |
| **TVI_FIRST** | Inserts the item at the beginning of the list. |
| **TVI_LAST** | Inserts the item at the end of the list. |
| **TVI_ROOT** | Add the item as a root item. |
| **TVI_SORT** | Inserts the item into the list in alphabetical order. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.itemex`

**Type: **[TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa)****

[Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). [TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa) structure that contains information about the item to add.

### `DUMMYUNIONNAME.item`

**Type: **[TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema)****

[TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema) structure that contains information about the item to add.

## Remarks

The unions in this structure have been updated to work with compilers that do not support nameless unions. If your compiler does not support nameless unions, define the NONAMELESSUNION token before including the commctrl.h header file.

**Important** Using TVI_LAST to insert an item into a tree-view node that already contains a large number of items can take a long time, causing the application to stop responding until the insert operation completes.

> [!NOTE]
> The commctrl.h header defines TVINSERTSTRUCT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).